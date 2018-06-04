
#include "stdafx.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "utility.h"
#include "field.h"

void checking(int **field, int **status, int *r1, int *r2, int *c1, int *c2) {
	if (*r1 == *r2 && *c1 == *c2) {
		printf("\n\n\t Nie mozesz wybrac dwa razy tego samego pola");
	}
	else if (status[*r1 - 1][*c1 - 1] == 1 || status[*r2 - 1][*c2 - 1] == 1) {            //r1-1 itd. poniewa¿ tablica zaczyna siê od 0, 
		printf("\n\n\t Nie mozesz wybrac pola, ktore juz wczesniej zostalo trafione");    //a u¿ytkownik podaje wartoœæ od 1
	}
	else if (field[*r1 - 1][*c1 - 1] != field[*r2 - 1][*c2 - 1]) {
		printf("\n\n\t Nie udalo sie, sproboj jeszcze raz!");
	}
	else if (field[*r1 - 1][*c1 - 1] == field[*r2 - 1][*c2 - 1]) {
		printf("\n\n\t Trafiles!");

		status[*r1 - 1][*c1 - 1] = 1;
		status[*r2 - 1][*c2 - 1] = 1;

	}
}

void game(int **field, int**status, int gameover, int moves, int row, int column) {
	int r1 = 100;         //wszystkie dane maj¹ wartoœæ pocz¹tkow¹ 100, ¿eby mog³a siê wygenerowaæ pocz¹tkowa plansza
	int c1 = 100;
	int r2 = 100;
	int c2 = 100;
	printField(row, column, status, field, r1, r2, c1, c2);

	while (gameover != 1) {

		chosing(&r1, &r2, &c1, &c2, row, column);
		checking(field, status, &r1, &r2, &c1, &c2);

		delay(1);
		system("CLS");
		r1--;
		c1--;
		r2--;
		c2--;

		printField(row, column, status, field, r1, r2, c1, c2);
		moves++;
		gameover = 1;
		for (int i = 0;i < row;i++) {
			for (int j = 0;j < column;j++) {
				if (status[i][j] == 0) {
					gameover = 0;
					break;
				}
			}
		}

	}

	printf("\n\n\t Gratulacje! Udalo Ci sie wygrac! Liczba ruchow, ktore wykonales: ");
	printf("%d", moves);
	file(row, column, moves);

	delay(10);
}
