#include <stdio.h>

int main() {
    int num1, num2, operacion, resultado;
    int repetir = 1;

    while (repetir) {
        printf("Dime un n�mero: ");
        scanf("%d", &num1);
        printf("Dime otro n�mero: ");
        scanf("%d", &num2);

        printf("Seleccione una operaci�n:\n");
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
                printf("Operaci�n no v�lida.\n");
                continue;
        }

        printf("El resultado es: %d\n", resultado);

        printf("�Desea realizar otra operaci�n? (1 para repetir, 0 para salir): ");
        scanf("%d", &repetir);

        if (repetir != 1) {
            repetir = 0;
        }
    }

    return 0;
}
