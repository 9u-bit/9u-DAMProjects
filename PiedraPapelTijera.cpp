/* Implementar el conocido juego Piedra, Papel, Tijera ofreciendo:
1. Modo Jugador vs Jugador
2. Modo Jugador vs Maquina
3. Al acabar, solicitar si se desea volver a jugar.
BONUS: Implementar un marcador. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int jugador1, jugador2, opcion, marcadorJugador1 = 0, marcadorJugador2 = 0;

    printf("Bienvenido al juego Piedra, Papel o Tijera!\n");

    do {
        printf("Elige una opción:\n");
        printf("1. Jugador vs Jugador\n");
        printf("2. Jugador vs Máquina\n");
        printf("3. Salir\n");
        printf("Ingrese el número de la opción: ");
        scanf("%d", &opcion);

        if (opcion == 3) {
            break;
        } else if (opcion == 1) {
            printf("Jugador 1, elige (1: Piedra, 2: Papel, 3: Tijera): ");
            scanf("%d", &jugador1);
            printf("Jugador 2, elige (1: Piedra, 2: Papel, 3: Tijera): ");
            scanf("%d", &jugador2);
        } else if (opcion == 2) {
            printf("Jugador 1, elige (1: Piedra, 2: Papel, 3: Tijera): ");
            scanf("%d", &jugador1);
            jugador2 = (rand() % 3) + 1;
            printf("La máquina elige: %d\n", jugador2);
        } else {
            printf("Opción no válida. Elige nuevamente.\n");
            continue;
        }

        if (jugador1 == jugador2) {
            printf("Es un empate!\n");
        } else if ((jugador1 == 1 && jugador2 == 3) || (jugador1 == 2 && jugador2 == 1) || (jugador1 == 3 && jugador2 == 2)) {
            printf("Jugador 1 gana!\n");
            marcadorJugador1++;
        } else {
            printf("Jugador 2 gana!\n");
            marcadorJugador2++;
        }

        printf("Resultado: Jugador 1 - %d | Jugador 2 - %d\n", marcadorJugador1, marcadorJugador2);
    } while (opcion != 3);

    printf("Gracias por jugar.\n");

    return 0;
}
