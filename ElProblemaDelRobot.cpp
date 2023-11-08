#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define MAP_SIZE 10
#define GAS_COST 10

int i;
int j;
int robotX, robotY;
int gasoline = 100;
char choice;
int rX, rY;

void displayMap(int robotX, int robotY) {
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            if (i == robotX && j == robotY) {
                printf("R "); 
            } else if (i == rX && j == rY) {
                printf("R ");
            } else {
                printf(". ");  
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    printf("Introduzca la posición inicial del robot (X Y): ");
    fflush(stdin);
    scanf("%d %d", &robotX, &robotY);
    
    rX = rand() % MAP_SIZE;
    rY = rand() % MAP_SIZE;

    while (1) {
        system("cls");
        
        displayMap(robotX, robotY);
        
        if (robotX == rX && robotY == rY) {
            printf("¡Has llegado al destino 'R'! El juego ha terminado.\n");
            break;
        }

        printf("Position: (%d, %d)\n", robotX, robotY);
        printf("Gasoline: %d\n", gasoline);
        printf("Options: (W)norte, (S)sur, (D)este, (A)oeste, (X)salir\n");
        
        fflush(stdin);
        scanf("%c", &choice);
        
        if (choice == 'W' || choice == 'w') {
            if (robotX > 0) {
                robotX--;
                gasoline -= GAS_COST;
            }
        } else if (choice == 'S' || choice == 's') {
            if (robotX < MAP_SIZE - 1) {
                robotX++;
                gasoline -= GAS_COST;
            }
        } else if (choice == 'D' || choice == 'd') {
            if (robotY < MAP_SIZE - 1) {
                robotY++;
                gasoline -= GAS_COST;
            }
        } else if (choice == 'O' || choice == 'o') {
            if (robotY > 0) {
                robotY--;
                gasoline -= GAS_COST;
            }
        } else if (choice == 'X' || choice == 'x') {
            break;
        }
        
        if (rand() % 10 == 0) {
            printf("Apareció un bidón de gasolina!\n");
            gasoline = 100;
        }
    }

    return 0;
}
