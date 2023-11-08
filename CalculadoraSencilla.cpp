/* Realizar un programa que pida al usuario dos números por teclado y después solicite que se escoja de entre 4 operaciones: sumar, restar, multiplicar o dividir.
En función de lo elegido se mostrará por pantalla el resultado de la operación.
Se debe permitir la repetición del programa, dando opción por pantalla al usuario de si "desea volver a hacer otra operación".
Se debe vigilar que si el usuario mete como segundo número un cero y además elige una división el programa le permita informarle en vez de fallar. */

#include <stdio.h>

int main() {
    int num1, num2, operacion, resultado;
    int repetir = 1;

    while (repetir) {
        printf("Dime un número: ");
        scanf("%d", &num1);
        printf("Dime otro número: ");
        scanf("%d", &num2);

        printf("Seleccione una operación:\n");
        printf("1. Sumar\n");
        printf("2. Restar\n");
        printf("3. Multiplicar\n");
        printf("4. Dividir\n");
        scanf("%d", &operacion);

        switch (operacion) {
            case 1:
                resultado = num1 + num2;
                break;
            case 2:
                resultado = num1 - num2;
                break;
            case 3:
                resultado = num1 * num2;
                break;
            case 4:
                if (num2 != 0) {
                    resultado = num1 / num2;
                } else {
                    printf("No puedes dividir por cero.\n");
                    continue;
                }
                break;
            default:
                printf("Operación no válida.\n");
                continue;
        }

        printf("El resultado es: %d\n", resultado);

        printf("¿Desea realizar otra operación? (1 para repetir, 0 para salir): ");
        scanf("%d", &repetir);

        if (repetir != 1) {
            repetir = 0;
        }
    }

    return 0;
}
