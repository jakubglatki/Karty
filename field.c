
#include "stdafx.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void shuffle(int **field, int row, int column)
{
	srand((unsigned)time(NULL));
	int *values;

	values = malloc(sizeof *values * (column*row + 1));

	for (int i = 0;i < (row * column) / 2;i++) {
		values[i] = i + 1;
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
			printf("%d ", field[r][c]);    //Ta linijka pokazuje wylosowane wartoœci w celu u³atwienia testów,
			i = i + 1;                     //je¿eli gra odniesie sukces komercyjny to zostanie usuniêta
		}
		printf("\n");
	}
	free(values);
}


void printField(int row, int column, int **status, int **field, int r1, int r2, int c1, int c2) {
	printf("\n \t   ");
	for (int i = 1;i <= column;i++) {
		printf("%d  ", i);
	}
	printf("\n \t  ");
	for (int i = 1;i <= column;i++)
	{
		if (i < 10) {
			printf("---");
		}
		else {
			printf("----");
		}
	}
	printf("\n\t");
	for (int j = 0;j < row;j++) {
		printf("%d|", j + 1);
		for (int k = 0;k < column;k++) {
			if ((j == r1) && (k == c1)) {
				if (field[r1][c1] < 10) {
					printf(" %d ", field[r1][c1]);
				}
				else printf(" %d", field[r1][c1]);
			}
			else if ((j == r2) && (k == c2)) {
				if (field[r2][c2] < 10) {
					printf(" %d ", field[r2][c2]);
				}
				else printf(" %d", field[r2][c2]);
			}
			else if (status[j][k] == 1) {
				if (field[j][k] < 10) {
					printf(" %d ", field[j][k]);
				}
				else printf(" %d", field[j][k]);
			}

			else {
				printf(" # ");
			}
		}
		printf("\n\t");
	}
}