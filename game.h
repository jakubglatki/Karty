#ifndef GAME_H
#define GAME_H

// Funkcja sprawdzaj¹ca, czy u¿ytkownikowi uda³o siê odgadn¹æ jendakowe pola, 
// oraz czy odkry³ prawid³owe pola
void checking(int **field, int **status, int *r1, int *r2, int *c1, int *c2);

// Funkcja steruj¹ca dzia³aniem gry, uruchamiaj¹ca inne funkcje niezbêdne
// do prawid³owego przebiegu rozgrywki
void game(int **field, int**status, int gameover, int moves, int row, int column);


#endif