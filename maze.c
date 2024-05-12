#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

#define MAPSIZE 256
#define MAPLENGTH 16

int map[MAPSIZE] = {
   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
   1,0,0,0,0,2,0,0,2,1,1,0,0,0,0,1,
   1,0,2,0,1,0,1,1,0,0,0,0,0,1,0,1,
   1,0,2,2,1,0,0,2,0,0,0,0,0,1,0,1,
   1,0,2,0,0,0,0,2,2,0,0,2,2,1,0,1,
   1,0,0,1,2,2,2,0,0,0,0,0,2,0,2,1,
   1,0,0,0,0,0,2,0,0,0,0,0,2,0,2,1,
   1,0,2,0,0,2,0,2,0,0,2,0,0,0,0,1,
   1,0,2,2,0,2,0,0,2,2,0,2,0,0,0,1,
   1,0,0,2,0,2,2,0,2,2,0,0,2,0,2,1,
   1,2,0,2,0,0,0,2,0,0,0,2,0,0,2,1,
   1,2,1,0,0,0,2,0,0,0,0,2,0,2,0,1,
   1,0,1,1,2,2,0,2,2,0,2,0,0,1,2,1,
   1,0,0,2,0,0,0,0,0,2,0,1,0,1,0,1,
   1,1,0,0,1,0,1,1,1,0,0,1,0,0,0,1,
   1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

int playerX = 1;
int playerY = 2;

void drawMap() {
    system("CLS");
    
    for (int cell = 0; cell < MAPSIZE; cell++) {

        
        if (cell == playerX + ((playerY - 1) * MAPLENGTH)) {
            printf("P ");
        }
        else if (map[cell] == 2) {
            printf("##");
        }
        else {
            if (cell % MAPLENGTH == 0) {
                
            if (map[cell] == 1) printf("\n||");
            else printf("\n  ");
            
            }
            
            else {
            if (map[cell] == 1) printf("||");
            else printf("  ");
            }
        }
    }
}

int main() {
    char key;

    system("title MAZE");
    drawMap();
    while (1) {
        key = getch();
       
        int currentCell = (playerX + ((playerY - 1) * MAPLENGTH));
        if (key == 75 || key == 97) { // esquerda
            if (map[currentCell - 1] == 0 && playerX % MAPLENGTH != 0) {
              playerX--;
            }
            else if (map[currentCell - 1] == 2 && map[currentCell - 2] == 0 && playerX % MAPLENGTH != 0) {
              map[(currentCell) - 1] = 0;
              map[(currentCell) - 2] = 2;
              playerX--;
            }          
            drawMap();
        }
        if (key == 72 || key == 119) { // cima
            if (map[currentCell  - MAPLENGTH] == 0 && playerX % MAPLENGTH != 0) {
              playerY--;
            }
            else if (map[currentCell - MAPLENGTH] == 2 && map[currentCell - MAPLENGTH * 2] == 0 && playerX % MAPLENGTH != 0) {
              map[(currentCell) - MAPLENGTH * 2] = 2;
              map[(currentCell) - MAPLENGTH] = 0;
              playerY--;
            }
            drawMap();
        }
        if (key == 77 || key == 100) { // direita
            if (map[(playerX + ((playerY - 1) * MAPLENGTH)) + 1] == 0 && playerX % MAPLENGTH != 0) {
              playerX++;
            }
            else if (map[currentCell + 1] == 2 && map[currentCell + 2] == 0 && playerX % MAPLENGTH != 0) {
              map[(currentCell) + 1] = 0;
              map[(currentCell) + 2] = 2;
              playerX++;
            }
            drawMap();
        }
        if (key == 80 || key == 115) { // baixo
            if (map[(playerX + ((playerY - 1) * MAPLENGTH)) + MAPLENGTH] == 0 && playerX % MAPLENGTH != 0) {
              playerY++;
            }
            else if (map[currentCell + MAPLENGTH] == 2 && map[currentCell + MAPLENGTH * 2] == 0 && playerX % MAPLENGTH != 0) {
              map[(currentCell) + MAPLENGTH * 2] = 2;
              map[(currentCell) + MAPLENGTH] = 0;
              playerY++;
            }
            drawMap();
        }
    }
    return 0;
}
