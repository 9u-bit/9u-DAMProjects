#include <stdio.h>

int main() {
    int saldo = 10;
    char tirada[3];

    printf("Bienvenido a la tragaperras\n");

    while (saldo > 0) {
        printf("\nSaldo actual: %d€\n", saldo);
        printf("Presiona Enter para lanzar la tragaperras (o 'q' para salir): ");
        getchar();

        tirada[0] = tirada[1] = tirada[2] = 'N'; // Siempre obtenemos 'N'

        printf("Tirada: %c %c %c\n", tirada[0], tirada[1], tirada[2]);

        if (tirada[0] == tirada[1] && tirada[1] == tirada[2]) {
            switch (tirada[0]) {
                case 'N':
                    saldo += 1;
                    break;
            }

            printf("¡Has ganado %d€!\n", saldo);
        } else {
            saldo -= 1;
            printf("No has ganado nada. Inténtalo de nuevo.\n");
        }
    }

    printf("Gracias por jugar. Tu saldo final es: %d€\n", saldo);

    return 0;
}
