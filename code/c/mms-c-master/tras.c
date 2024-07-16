#include <stdio.h>
#include <stdlib.h>
#include "API.h"

#define MAX_MAZE_SIZE 16
#define MAX_STEPS 1000  // Maximum number of steps allowed

void log(char* text) {
    fprintf(stderr, "%s\n", text);
    fflush(stderr);
}

int main(int argc, char* argv[]) {
    int maze_width = API_mazeWidth();
    int maze_height = API_mazeHeight();

    // Check if the maze size is within the maximum allowed size
    if (maze_width > MAX_MAZE_SIZE || maze_height > MAX_MAZE_SIZE) {
        log("Error: Maze size exceeds the maximum allowed size.");
        return 1;
    }

    // Create a 2D array to track visited cells
    int** visited = (int**)malloc(maze_height * sizeof(int*));
    if (visited == NULL) {
        log("Error: Memory allocation failed.");
        return 1;
    }

    for (int i = 0; i < maze_height; i++) {
        visited[i] = (int*)calloc(maze_width, sizeof(int));
        if (visited[i] == NULL) {
            log("Error: Memory allocation failed.");
            for (int j = 0; j < i; j++) {
                free(visited[j]);
            }
            free(visited);
            return 1;
        }
    }

    int wall = 1;
    int row = 15, col = 0;
    int dir = 1; // Initial direction: 0 (up), 1 (right), 2 (down), 3 (left)
    int steps = 0;

    log("Running...");
    API_setColor(0, 0, 'G');
    API_setText(0, 0, "abc");

    while (steps < MAX_STEPS) {
        // Check if the current cell has been visited before
        visited[row][col] = 1;

        if (wall == 1) {
            if (!API_wallLeft()) {
                API_turnLeft();
                dir = (dir + 3) % 4;
            }
            while (API_wallFront()) {
                API_turnRight();
                dir = (dir + 1) % 4;
            }

            // Update the row and column based on the current direction
            int new_row = row, new_col = col;
            switch (dir) {
                case 0: new_row--; break;
                case 1: new_col++; break;
                case 2: new_row++; break;
                case 3: new_col--; break;
            }

            // Check if the new position is within the maze boundaries
            if (new_row >= 0 && new_row < maze_height && new_col >= 0 && new_col < maze_width) {
                if (API_moveForward()) {
                    row = new_row;
                    col = new_col;
                    steps++;
                } else {
                    log("Deadlock detected!");
                    break;
                }

                if (visited[row][col]) {
                    log("Revisiting a cell!");
                    wall *= -1;
                }
            } else {
                log("Trying to move outside the maze boundaries.");
            }
        } else {
            visited[row][col] = 1;

            if (!API_wallRight()) {
                API_turnRight();
                dir = (dir + 1) % 4;
            }
            while (API_wallFront()) {
                API_turnLeft();
                dir = (dir + 3) % 4;
            }

            // Update the row and column based on the current direction
            int new_row = row, new_col = col;
            switch (dir) {
                case 0: new_row--; break;
                case 1: new_col++; break;
                case 2: new_row++; break;
                case 3: new_col--; break;
            }

            // Check if the new position is within the maze boundaries
            if (new_row >= 0 && new_row < maze_height && new_col >= 0 && new_col < maze_width) {
                if (API_moveForward()) {
                    row = new_row;
                    col = new_col;
                    steps++;
                } else {
                    log("Deadlock detected!");
                    break;
                }
            } else {
                log("Trying to move outside the maze boundaries.");
            }
        }
    }

    if (steps >= MAX_STEPS) {
        log("Maximum number of steps exceeded. Unable to solve the maze.");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < maze_height; i++) {
        free(visited[i]);
    }
    free(visited);

    return 0;
}