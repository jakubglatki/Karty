// Karty.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdio.h>

void free_memory(int **tab, int col) {
	
	for (int i = 0; i < col; i++) {
			free(tab[i]);
		}
	
	free(tab);
}


void shuffle(int **field, int row, int column)
{
	srand((unsigned)time(NULL));
	int *values;

	values = malloc(sizeof *values * (column*row + 1));
	
	for (int i = 0;i < (row * column)/2;i++) {
		values[i] = i+1;
		values[i + (row*column) / 2] = i + 1;
		
	}
	for (int i = 0;i < row*column;i++) {

		printf("%d ", values[i]);
	}
	printf("\n\n");

	
		for (int x = 0; x<(row*column); x++)
		{
			int i = rand() % (row*column);
			int temp = values[x];
			values[x] = values[i];
			values[i] = temp;
		}

	int i = 0;
	for (int r = 0; r<row; r++) 
	{
		for (int c = 0; c<column; c++)
		{
			field[r][c] = values[i];
			printf("%d ", field[r][c]);
			i = i + 1;
		}
		printf("\n");
	}
	free(values);
}


void start_field(int row, int column, int **status) {
	printf("\n \t   ");
	for (int i = 1;i <= column;i++) {
		printf("%d ", i);
	}
	printf("\n \t  ");
	for (int i = 1;i <= column;i++)
	{
		if (i < 10) {
			printf("--");
		}
		else {
			printf("---");
		}
	}
	printf("\n\t");
	for (int j = 0;j < row;j++) {
		printf("%d|", j+1);
		for (int k = 0;k < column;k++) {
			printf(" #");
			status[j][k] = 0;
		}
		printf("\n\t");
	}
}

void game(int **field, int**status, int gameover) {
	int r1, r2, c1, c2;
	
	while (gameover != 1) {
		printf("\t Wybierz rzad pierwszego pola: ");
		scanf("%d", &r1);
		printf("\t Wybierz kolumne pierwszego pola: ");
		scanf("%d", &c1);
		printf("\t Wybierz rzad drugiego pola: ");
		scanf("%d", &r2);
		printf("\t Wybierz kolumne drugiego pola: ");
		scanf("%d", &c2);

		if (r1 == r2 & c1 == c2) {
			printf("\n\n\t Nie mozesz wybrac dwa razy tego samego pola");
		}
		else if (status[r1][c1] == 1 | status[r2][c2] == 1) {
			printf("\n\n\t Nie mozesz wybrac pola, ktore juz wczesniej zostalo trafione");
		}
		else if (field[r1][c1] == field[r2][c2]) {
			printf("\n\n\t Trafiles!");
			status[r1][c1] == 1;
			status[r2][c2] == 1;
		}
	}
}

int main() {

	int f_row, f_col;
	int **field;

	int row, col;
	int **status;

	int gameover = 0;
	int moves = 0;

	// Pobranie danych
	printf(" Liczba wierszy: ");
	scanf("%d", &f_row);
	printf("\n Liczba kolmun: ");
	scanf("%d", &f_col);
	if (f_row <=1 | f_col<= 1) {
		printf("\n\n\n\t Liczba kolumn i wierszy musi byc wieksza niz 1\n");
		return 0;
	}
	if ((f_row*f_col) % 2 != 0) {
		printf("\n\n\n\t Liczba pol musi byc parzysta(musisz wybrac parzysta liczbe wierszy i/lub kolumn\n");
		return 0;
	}

	row = f_row;
	col = f_col;

	field = (int**)malloc(f_row * sizeof(int*)); 
	for (int i = 0; i < f_row; i++) {
		field[i] = (int*)malloc(f_col * sizeof(int));
	}

	status = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++) {
		status[i] = (int*)malloc(col * sizeof(int));
	}
	shuffle(field, row, col);
	start_field(row, col, status);
	game(field, status, gameover);

	
	free_memory(field, f_col);
	free_memory(status, col);
	
	return 0;
}



