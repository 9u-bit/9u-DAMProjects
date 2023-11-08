/* En un mundo circular y bidimensional de 10 x 10, un robot comienza en una posición dada por el usuario.
1. El robot, puede moverse en las direcciones: norte, sur, este y oeste.
2. El robot comienza con 100 unidades de gasolina.
3. Cada vez que se mueve una casilla gasta 10 unidades de gasolina.
4. Aleatoriamente, aparece en otra posición del mapa, un bidón de gasolina. Cada vez que el robot tome el bidón, recarga a 100 su depósito de gasolina.
5. Se debe imprimir un mapa en caracteres ASCII indicando la posición del robot, así como una interfaz rudimentaria que muestre la posición, la gasolina restante y las opciones de movimiento al usuario. ç
BONUS (v2.0): Implementar el programa utilizando arrays */

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
