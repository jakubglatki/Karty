#ifndef GAME_H
#define GAME_H

// Funkcja sprawdzaj�ca, czy u�ytkownikowi uda�o si� odgadn�� jendakowe pola, 
// oraz czy odkry� prawid�owe pola
void checking(int **field, int **status, int *r1, int *r2, int *c1, int *c2);

// Funkcja steruj�ca dzia�aniem gry, uruchamiaj�ca inne funkcje niezb�dne
// do prawid�owego przebiegu rozgrywki
void game(int **field, int**status, int gameover, int moves, int row, int column);


#endif