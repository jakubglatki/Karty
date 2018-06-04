#include "stdafx.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "utility.h"


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

void free_memory(int **tab, int col) {

	for (int i = 0; i < col; i++) {
		free(tab[i]);
	}

	free(tab);
}
