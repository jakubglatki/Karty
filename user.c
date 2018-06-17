#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "stdafx.h"

int getNumber()
{
	int number;
	int reads = scanf("%d", &number);
	int check = 0;
	for (int i = 0;i<8;i++) {
		if (i + 1 == number) {
			check = 1;
			break;
		}
	}
	if (check != 1) {
		printf("\n\n\t Musisz wpisac cyfre z prawidlowego zakresu ");
	}
	while (reads != 1)
	{
		getchar();
		reads = scanf("%d", &number);
	}

	return number;
}


void chosing(int *row1, int *row2, int *column1, int *column2, int row, int column) {
	int check = 1;
	while (check == 1) {       //kiedy u¿ytkownik poda jedn¹ z danych nieprawid³owo, to zaczyna wypisywaæ wszystkie
		check = 0;             //od pocz¹tku
		printf("\n\n\t Wybierz rzad pierwszego pola: ");
		*row1 = getNumber();
		if (*row1 < 1 || *row1>row) {
			printf("\n\n\t Wybrano nieprawidlowy rzad");
			check = 1;
			continue;
		}
		printf("\n\t Wybierz kolumne pierwszego pola: ");
		*column1 = getNumber();
		if (*column1 < 1 || *column1>column) {
			printf("\n\n\t Wybrano nieprawidlowa kolumne");
			check = 1;
			continue;
		}
		printf("\n\t Wybierz rzad drugiego pola: ");
		*row2 = getNumber();
		if (*row2 < 1 || *row2>row) {
			printf("\n\n\t Wybrano nieprawidlowy rzad");
			check = 1;
			continue;
		}
		printf("\n\t Wybierz kolumne drugiego pola: ");
		*column2 = getNumber();
		if (*column2 < 1 || *column2>column) {
			printf("\n\n\t Wybrano nieprawidlowa kolumne");
			check = 1;
			continue;
		}
		if (check != 1) {
			break;
		}
	}
}


void takeData(int *f_row, int *f_col) {
	int ok = 0;
	while (ok != 1) {
		printf("\n\n\t Liczba wierszy: ");
		*f_row = getNumber();
		printf("\n\n\t Liczba kolmun: ");
		*f_col = getNumber();

		if (*f_row <= 1 || *f_col <= 1) {
			printf("\n\n\n\t Liczba kolumn i wierszy musi byc wieksza niz 1\n");

		}
		else if (*f_row >= 9 || *f_col >= 9) {
			printf("\n\n\n\t Liczba kolumn i wierszy musi byc mniejsza niz 9\n");
		}
		else if ((*f_row * *f_col) % 2 != 0) {
			printf("\n\n\n\t Liczba pol musi byc parzysta(musisz wybrac parzysta liczbe wierszy i/lub kolumn)\n");
			continue;
		}
		else {
			ok = 1;
			system("CLS");
		}
	}
}