// Karty.cpp : Defines the entry point for the console application.
//
#define _CRTDBG_MAP_ALLOC  
#include "stdafx.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h> 
#include "user.h"
#include "utility.h"
#include "field.h"
#include "game.h"

int main(int argc, char * argv[]) {

	int f_row, f_column;
	int **field;

	int row, col;
	int **status;

	int gameover = 0;
	int moves = 0;

	// Pobranie danych
	takeData(&f_row, &f_column);

	row = f_row;
	col = f_column;

	field = (int**)malloc(f_row * sizeof(int*)); 
	for (int i = 0; i < f_row; i++) {
		field[i] = (int*)malloc(f_column * sizeof(int));
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
	
	free_memory(field, f_column);
	free_memory(status, col);
	_CrtDumpMemoryLeaks(); //sprawdzanie wycieków pamięci
	return 0;
}



