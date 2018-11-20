// ConsoleApplication252.cpp : Defines the entry point for the console application.
//

#include"stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void drawMatrix(int matrix[3][3]) {
	int i, j, k;
	char structuraX[5][11] = {
		"*       * ",
		"  *   *   ",
		"    *     ",
		"  *   *   ",
		"*       * "
	};
	char structuraO[5][11] = {
		"  * * *   ",
		"*       * ",
		"*       * ",
		"*       * ",
		"  * * *   "
	};
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 3; k++) {
				if (matrix[i][k] == 0 && j == 2) {
					printf("     %d    ", 9 - (i * 3 + 2 - k));
				}
				else if (matrix[i][k] == 0) {
					printf("          ");
				}
				else if (matrix[i][k] == 1) {
					printf("%s", structuraX[j]);
				}
				else if (matrix[i][k] == 2) {
					printf("%s", structuraO[j]);
				}
				if (k == 2) {
					printf("\n");
				}
				else {
					printf("|");
				}
			}

		}
		if (i != 2) {
			printf("----------------------------------\n");
		}
	}
}

void drawRules(int matrix[3][3]) {
	printf("Bine ai venit in jocul X si 0\n");
	printf("Matricea de joc este\n");
	drawMatrix(matrix);
}

int checkAvailable(int matrix[3][3], int position) {
	if (position == 1 && matrix[2][0] == 0) {
		return 1;
	}
	if (position == 1 && matrix[2][0] == 0) {
		return 1;
	}
	if (position == 2 && matrix[2][1] == 0) {
		return 1;
	}
	if (position == 3 && matrix[2][2] == 0) {
		return 1;
	}
	if (position == 4 && matrix[1][0] == 0) {
		return 1;
	}
	if (position == 5 && matrix[1][1] == 0) {
		return 1;
	}
	if (position == 6 && matrix[1][2] == 0) {
		return 1;
	}
	if (position == 7 && matrix[0][0] == 0) {
		return 1;
	}
	if (position == 8 && matrix[0][1] == 0) {
		return 1;
	}
	if (position == 9 && matrix[0][2] == 0) {
		return 1;
	}
	return 0;
}

void setMove(int matrix[3][3], int position, int value) {
	if (position == 1) {
		matrix[2][0] = value;
	}
	if (position == 1) {
		matrix[2][0] = value;
	}
	if (position == 2) {
		matrix[2][1] = value;
	}
	if (position == 3) {
		matrix[2][2] = value;
	}
	if (position == 4) {
		matrix[1][0] = value;
	}
	if (position == 5) {
		matrix[1][1] = value;
	}
	if (position == 6) {
		matrix[1][2] = value;
	}
	if (position == 7) {
		matrix[0][0] = value;
	}
	if (position == 8) {
		matrix[0][1] = value;
	}
	if (position == 9) {
		matrix[0][2] = value;
	}
}

int checkGameWin(int matrix[3][3]) {
	//Verificare pe linii
	if (matrix[0][0] != 0 && matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2]) {
		return 1;
	}
	if (matrix[1][0] != 0 && matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2]) {
		return 1;
	}
	if (matrix[2][0] != 0 && matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2]) {
		return 1;
	}
	//Verificare pe coloane
	if (matrix[0][0] != 0 && matrix[0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0]) {
		return 1;
	}
	if (matrix[0][1] != 0 && matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1]) {
		return 1;
	}
	if (matrix[0][2] != 0 && matrix[0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2]) {
		return 1;
	}
	//Verificare pe diagonale
	if (matrix[0][0] != 0 && matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]) {
		return 1;
	}
	if (matrix[0][2] != 0 && matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]) {
		return 1;
	}
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (matrix[i][j] == 0) {
				return 0;
			}
		}
	}
	return 2;
}

void startGame(int matrix[3][3]) {
	int firstPlayer, nextPlayer = 0;
	printf("Primul jucator alege litera 1 pentru X si 2 pentru O\n");
	scanf("%d", &firstPlayer);
	while (1) {
		printf("Alege unde vrei sa pui litera\n");
		int position;
		scanf("%d", &position);
		if (checkAvailable(matrix, position) == 1) {
			if (nextPlayer == 0 && firstPlayer == 1) {
				//pune miscare pentru primul cu X
				setMove(matrix, position, 1);
			}
			else if (nextPlayer == 0 && firstPlayer == 2) {
				//pune miscare pentru primul cu O
				setMove(matrix, position, 2);
			}
			else if (nextPlayer == 1 && firstPlayer == 1) {
				//pune miscare pentru al doilea cu O
				setMove(matrix, position, 2);
			}
			else {
				//pune miscare pentru al doilea cu X
				setMove(matrix, position, 1);
			}

			if (checkGameWin(matrix) == 1) {
				system("clear");
				drawMatrix(matrix);
				if (nextPlayer == 0) {
					printf("A castigat jucatorul 1\n");
				}
				else {
					printf("A castigat jucatorul 2\n");
				}
				return;
			}
			else if (checkGameWin(matrix) == 2) {
				system("clear");
				drawMatrix(matrix);
				printf("Egalitate\n");
				return;
			}
			//Schimbarea urmatorului jucator dupa ce a ales unul
			if (nextPlayer == 0) {
				nextPlayer = 1;
			}
			else if (nextPlayer == 1) {
				nextPlayer = 0;
			}
		}
		else {
			printf("Alege o casuta libera\n");
		}
		system("clear");
		drawMatrix(matrix);
	}
}


int main() {
	//0 este absent
	//1 este pus X
	//2 este pus 0
	int matrix[3][3] = { { 0, 0, 0 },{ 0, 0, 0 },{ 0, 0, 0 } };

	system("clear");

	drawRules(matrix);
	startGame(matrix);
	return 0;
}
