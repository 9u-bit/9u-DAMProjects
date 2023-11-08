/* Sean dos dinosaurios que impiezan cada uno con 10 puntos de vida (HP), elaborar un programa que por turnos permita a cada dinosaurio las siguientes opciones:
1. Morder (Quitra 2 puntos de vida al otro dinosaurio)
2. Defender (El otro dinosaurio tiene un 50% de posibilidad de fallar el mordisco en su turno)
3. Huir (Se le da la victoria al otro dinosaurio)
El primer dinosaurio cuya vida llegue a 0, pierede */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// for 50%
bool randomSuccess() {
    return (rand() % 2) == 0;
}

int main() {
    srand(time(NULL));

    int dino1HP = 10;
    int dino2HP = 10;

    printf("Bienvenido al juego de la batalla de dinosaurios!\n");
    printf("Tienes el control del Dinosaurio 1.\n");

    while (dino1HP > 0 && dino2HP > 0) {
        printf("Elige tu acción:\n");
        printf("1. Morder\n");
        printf("2. Defender\n");
        printf("3. Huir\n");

        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            dino2HP -= 2;
            printf("¡Dinosaurio 1 ataca! Dinosaurio 2 pierde 2 HP.\n");
        } else if (choice == 2) {
            printf("Dinosaurio 1 se defiende. El ataque del dinosaurio 2 es menos eficaz.\n");
        } else if (choice == 3) {
            printf("Dinosaurio 1 huye. ¡Dinosaurio 2 gana!\n");
            break;
        } else {
            printf("Elección no válida. Por favor, elija 1, 2 o 3.\n");
        }

        if (dino2HP > 0) {
            choice = rand() % 3;

            if (choice == 0) {
                if (randomSuccess()) {
                    if (choice == 2) {
                        printf("¡El ataque del Dinosaurio 2 es menos efectivo debido a la defensa del Dinosaurio 1!\n");
                        dino1HP -= 1;
                    } else {
                        dino1HP -= 2;
                    }
                    printf("¡Dinosaurio 2 ataca! Dinosaurio 1 pierde 2 HP.\n");
                } else {
                    printf("¡El ataque del Dinosaurio 2 falló!\n");
                }
            } else if (choice == 2) {
                printf("Dinosaurio 2 se defiende. El ataque del dinosaurio 1 es menos eficaz.\n");
            } else if (choice == 3) {
                printf("Dinosaurio 2 huye. ¡Dinosaurio 1 gana!\n");
                break;
            }
        }

        printf("Dinosaurio 1 HP: %d\n", dino1HP);
        printf("Dinosaurio 2 HP: %d\n", dino2HP);
    }

    if (dino1HP <= 0) {
        printf("Dinosaurio 2 wins!\n");
    } else {
        printf("Dinosaurio 1 wins!\n");
    }

    return 0;
}
