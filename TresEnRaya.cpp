// Realizar el juego de las tres en raya siguiendo las siguientes reglas
// 1 - se pide el nombre de jugador 1 y 2, y a partir de ese momento, el juego se refiere a los jugadores por su nombre [OK]
// 2 - las fichas pueden ser numeros (0, 1, 2, o 3) [OK]
// 3 - el primer jugador elige ficha [OK]
// 4 - el segundo jugador elige ficha de las restantes [OK]
// 5 - empieza el juego y tira el jugador 1 [OK]
// 6 - el jugador 1 no puede elegir 0,0 [NO]
// 7 - empieza en 1,1 [NO]
// 8 - el tablero se dibuja en pantalla [OK]
// nota: centro de la pantalla, cada recuardo son 3 posiciones, usar ascii [OK]

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void displayBoard(char board[3][3]) {
    system("cls");
    gotoxy(50, 5);
    printf("%c %c %c %c %c %c %c\n", 218, 196, 194, 196, 194, 196, 191);
    gotoxy(50, 6);
    printf("%c %c %c %c %c %c %c\n", 179, board[0][0], 179, board[0][1], 179, board[0][2], 179);
    gotoxy(50, 7);
    printf("%c %c %c %c %c %c %c\n", 195, 196, 197, 196, 197, 196, 180);
    gotoxy(50, 8);
    printf("%c %c %c %c %c %c %c\n", 179, board[1][0], 179, board[1][1], 179, board[1][2], 179);
    gotoxy(50, 9);
    printf("%c %c %c %c %c %c %c\n", 195, 196, 197, 196, 197, 196, 180);
    gotoxy(50, 10);
    printf("%c %c %c %c %c %c %c\n", 179, board[2][0], 179, board[2][1], 179, board[2][2], 179);
    gotoxy(50, 11);
    printf("%c %c %c %c %c %c %c\n", 192, 196, 193, 196, 193, 196, 217);
}

int checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }

    int draw = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                draw = 0;
                break;
            }
        }
        if (!draw) break;
    }

    if (draw) return 0;

    return -1;
}

int main() {
    char jugador1[20];
    char jugador2[20];
    int ficha1, ficha2;

    printf("Nombre del jugador 1: ");
    scanf("%s", jugador1);
    clearBuffer();

    printf("Nombre del jugador 2: ");
    scanf("%s", jugador2);
    clearBuffer();

    printf("%s, elige tu ficha (0, 1, 2, o 3): ", jugador1);
    scanf("%d", &ficha1);
    clearBuffer();

    printf("%s, elige tu ficha (0, 1, 2, o 3) diferente a la de %s: ", jugador2, jugador1);
    scanf("%d", &ficha2);
    clearBuffer();

    while (ficha1 < 0 || ficha1 > 3 || ficha2 < 0 || ficha2 > 3 || ficha1 == ficha2) {
        printf("Selecciones inválidas. Inténtalo de nuevo.\n");

        printf("%s, elige tu ficha (0, 1, 2, o 3): ", jugador1);
        scanf("%d", &ficha1);
        clearBuffer();

        printf("%s, elige tu ficha (0, 1, 2, o 3) diferente a la de %s: ", jugador2, jugador1);
        scanf("%d", &ficha2);
        clearBuffer();
    }

    int currentPlayer = 1;
    int row, col;
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    do {
        displayBoard(board);

        gotoxy(40, 15);
        printf("%s (%d), es tu turno. Elige una posición (1-3 1-3): ", (currentPlayer == 1) ? jugador1 : jugador2, (currentPlayer == 1) ? ficha1 : ficha2);
        scanf("%d %d", &row, &col);
        clearBuffer();

        if (board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = (currentPlayer == 1) ? ficha1 + '0' : ficha2 + '0';
        } else {
            printf("La posición ya está ocupada. Intenta de nuevo.\n");
            continue;
        }

        int gameStatus = checkWin(board, (currentPlayer == 1) ? ficha1 + '0' : ficha2 + '0');
        if (gameStatus == 1) {
            displayBoard(board);
            printf("%s ha ganado!\n", (currentPlayer == 1) ? jugador1 : jugador2);
            break;
        } else if (gameStatus == 0) {
            displayBoard(board);
            printf("¡Es un empate!\n");
            break;
        }

        currentPlayer = (currentPlayer == 1) ? 2 : 1;

    } while (1);

    return 0;
}
