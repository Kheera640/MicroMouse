#include <stdio.h>

#include "API.h"

void log(char* text) {
    fprintf(stderr, "%s\n", text);
    fflush(stderr);
}

int main(int argc, char* argv[]) {
    int a[16][16];
    a[15][0]=1;
    int dir =1;int left=1;
    int right=-1;
    int i=15;
    int j=0;
    log("Running...");
    API_setColor(0, 0, 'G');
    API_setText(0, 0, "abc");
    while (1) {
        if(left==1){
        if (!API_wallLeft()) {
            dir--;
            API_turnLeft();
        }
        while (API_wallFront()) {
            dir++;
            API_turnRight();
        }
        dir = (dir + 4) % 4;
        switch(dir)
        {
            case 0:
            a[i--][j]=1;
            break;
            case 1:
            a[i][j++]=1;
            break;
            case 2:
            a[i++][j]=1;
            break;
            case 3:
            a[i][j--]=1;
            break;
        }
        API_moveForward();
        if(a[i][j]==1)
        left*=-1;

        }
        if(right ==1)
        {
         if (!API_wallRight()) {
            dir--;
            API_turnRight();
        }
        while (API_wallFront()) {
            dir++;
            API_turnLeft();
        }
        dir = (dir + 4) % 4;
        switch(dir)
        {
            case 0:
            a[i--][j]=1;
            break;
            case 1:
            a[i][j++]=1;
            break;
            case 2:
            a[i++][j]=1;
            break;
            case 3:
            a[i][j--]=1;
            break;
        }
        API_moveForward();
        if(a[i][j]==1)
        right*=-1;
    }
    }

}