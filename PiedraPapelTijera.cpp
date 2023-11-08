#include <stdio.h>
#include <stdlib.h>

int main() {
    int jugador1, jugador2, opcion, marcadorJugador1 = 0, marcadorJugador2 = 0;

    printf("Bienvenido al juego Piedra, Papel o Tijera!\n");

    do {
        printf("Elige una opci�n:\n");
        printf("1. Jugador vs Jugador\n");
        printf("2. Jugador vs M�quina\n");
        printf("3. Salir\n");
        printf("Ingrese el n�mero de la opci�n: ");
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
            printf("La m�quina elige: %d\n", jugador2);
        } else {
            printf("Opci�n no v�lida. Elige nuevamente.\n");
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
