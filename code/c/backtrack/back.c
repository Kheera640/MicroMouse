#include <stdio.h>
#include <math.h>
#include "API.h"

void my_log(char* text) {
    fprintf(stderr, "%s\n", text);
    fflush(stderr);
}

void findpath(int i, int j, int vis[16][16], char orientation) {
    // Direction mapping
    char directions[4] = {'N', 'E', 'S', 'W'};
    int current_dir = 0; // Default to North

    // Mapping old direction to index
    for (int k = 0; k < 4; k++) {
        if (directions[k] == orientation) {
            current_dir = k;
            break;
        }
    }

    // Check walls and update grid between cells
    if (API_wallFront()) {
        // Assume 1 represents a wall between cells in the maze
        if (current_dir == 0 && i > 0) vis[i - 1][j] = 1; // North
        else if (current_dir == 1 && j < 15) vis[i][j] = 1; // East
        else if (current_dir == 2 && i < 15) vis[i][j] = 1; // South
        else if (current_dir == 3 && j > 0) vis[i][j - 1] = 1; // West
    }

    // Check walls on the right and update grid between cells
    if (API_wallRight()) {
        int right_dir = (current_dir + 1) % 4;
        // Assume 1 represents a wall between cells in the maze
        if (right_dir == 0 && i > 0) vis[i][j] = 1; // North
        else if (right_dir == 1 && j < 15) vis[i][j] = 1; // East
        else if (right_dir == 2 && i < 15) vis[i + 1][j] = 1; // South
        else if (right_dir == 3 && j > 0) vis[i][j] = 1; // West
    }

    // Check walls on the left and update grid between cells
    if (API_wallLeft()) {
        int left_dir = (current_dir + 3) % 4;
        // Assume 1 represents a wall between cells in the maze
        if (left_dir == 0 && i > 0) vis[i][j] = 1; // North
        else if (left_dir == 1 && j < 15) vis[i - 1][j] = 1; // East
        else if (left_dir == 2 && i < 15) vis[i][j - 1] = 1; // South
        else if (left_dir == 3 && j > 0) vis[i][j] = 1; // West
    }

    // Rest of your pathfinding logic...
}

int main(int argc, char* argv[]) {
    int vis[16][16] = {0};
    findpath(0, 0, vis, 'E'); // Assuming the initial orientation is East (can be adjusted)
    return 0;
}
