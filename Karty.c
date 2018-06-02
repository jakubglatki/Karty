// Karty.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>


void file(int row, int column, int moves) {
	FILE *stats;
	if ((stats = fopen("statystyki.txt", "a+")) == NULL) {
		printf("\n\n\tNie mozna otworzyc pliku do zapisu statystyk");
	}
	fprintf(stats, "Liczba kolumn: ");
	fprintf(stats, "%d", column);
	fprintf(stats, "\nLiczba wierszy: ");
	fprintf(stats, "%d", row);
	fprintf(stats, "\nLiczba ruchow potrzebna do ukonczenia gry: ");
	fprintf(stats, "%d\n", moves);
	fclose(stats);
}

void delay(int sec)
{
	int msec = 1000 * sec;
	clock_t start_time = clock();
	while (clock() < start_time + msec);
}

int getNumber()
{
	int number;
	int reads = scanf("%d", &number);
	int check = 0;
	for(int i=0;i<8;i++){
		if (i + 1 == number) {
			check = 1;
			break;
		}
	}
	if (check != 1) {
		printf("\n\n\t Musisz wpisac cyfre ");
	}
	while (reads != 1)
	{
		getchar();
		reads = scanf("%d", &number);
	}

	return number;
}


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


void start_field(int row, int column, int **status, int **field, int r1, int r2, int c1, int c2) {
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
			if ((j == r1) && (k == c1)) {
				printf(" %d", field[r1][c1]);
			}
			else if ((j == r2) && (k == c2)) {
				printf(" %d", field[j][k]);
			}
			else if (status[j][k] == 1) {
				printf(" %d", field[j][k]);
			}
			else if (status[j][k] == 1) {
				printf(" %d", field[j][k]);
			}
			else {
				printf(" #");
			}
		}
		printf("\n\t");
	}
}

void checking(int **field, int **status, int *r1, int *r2, int *c1, int *c2) {
	if (*r1 == *r2 && *c1 == *c2) {
		printf("\n\n\t Nie mozesz wybrac dwa razy tego samego pola");
	}
	else if (status[*r1 - 1][*c1 - 1] == 1 || status[*r2 - 1][*c2 - 1] == 1) {                     //r1-1 itd. ponieważ tablica zaczyna się od 0, a użytkownik podaje wartość od 1
		printf("\n\n\t Nie mozesz wybrac pola, ktore juz wczesniej zostalo trafione");
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

void chosing(int *r1, int *r2, int *c1, int *c2, int row, int column) {
	int check=1;
	while (check == 1) {
		check = 0;
		printf("\n\n\t Wybierz rzad pierwszego pola: ");
		*r1 = getNumber();
		if (*r1 < 1 || *r1>row) {
			printf("\n\n\t Wybrano nieprawidlowy rzad");
			check = 1;
			continue;
		}
		printf("\n\t Wybierz kolumne pierwszego pola: ");
		*c1 = getNumber();
		if (*c1 < 1 || *c1>column) {
			printf("\n\n\t Wybrano nieprawidlowa kolumne");
			check = 1;
			continue;
		}
		printf("\n\t Wybierz rzad drugiego pola: ");
		*r2 = getNumber();
		if (*r2 < 1 || *r2>row) {
			printf("\n\n\t Wybrano nieprawidlowy rzad");
			check = 1;
			continue;
		}
		printf("\n\t Wybierz kolumne drugiego pola: ");
		*c2 = getNumber();
		if (*c2 < 1 || *c2>column) {
			printf("\n\n\t Wybrano nieprawidlowa kolumne");
			check = 1;
			continue;
		}
		if (check != 1) {
			break;
		}
	}
}

void game(int **field, int**status, int gameover, int moves, int row, int column) {
	int r1 = 100;         //wszystkie dane mają wartość początkową 100, żeby mogła się wygenerować początkowa plansza
	int c1 = 100;
	int r2 = 100;
	int c2 = 100;
	start_field(row,column,status, field,r1,r2,c1,c2);

		while (gameover != 1) {

			chosing(&r1, &r2, &c1, &c2,row,column);
			checking(field, status, &r1, &r2, &c1, &c2);

			delay(1);
			system("CLS");
			r1--;
			c1--;
			r2--;
			c2--;

			start_field(row, column, status, field, r1, r2, c1, c2);
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

int main() {

	int f_row, f_col;
	int **field;

	int row, col;
	int **status;

	

	int gameover = 0;
	int moves = 0;

	// Pobranie danych

	int ok = 0;
	while (ok != 1) {
	printf("\n\n\t Liczba wierszy: ");
	f_row = getNumber();
	printf("\n\n\t Liczba kolmun: ");
	f_col = getNumber();

		if (f_row <= 1 || f_col <= 1) {
			printf("\n\n\n\t Liczba kolumn i wierszy musi byc wieksza niz 1\n");
		
		}
		else if (f_row >= 9 || f_col >= 9) {
			printf("\n\n\n\t Liczba kolumn i wierszy musi byc mniejsza niz 9\n");
		}
		else if ((f_row*f_col) % 2 != 0) {
			printf("\n\n\n\t Liczba pol musi byc parzysta(musisz wybrac parzysta liczbe wierszy i/lub kolumn)\n");
			continue;
		}
		else {
			ok = 1;
			system("CLS");
		}
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


	for (int j = 0;j < row;j++) {
		for (int k = 0;k < col;k++) {
			status[j][k] = 0;
		}
	}


	shuffle(field, row, col);
	game(field, status, gameover, moves, row, col);

	
	free_memory(field, f_col);
	free_memory(status, col);
	
	return 0;
}



