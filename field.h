#ifndef FIELD_H
#define FIELD_H

// Funkcja odpowiadaj�ca za wylosowanie poszczeg�lnych warto�ci p�l na planszy
void shuffle(int **field, int row, int column);

// Funkcja odpowiadaj�ca za wypisanie pola gry, kt�re r�ni si� w zale�no�ci
// od zaawansowania danej rozgrywki
void printField(int row, int column, int **status, int **field, int r1, int r2, int c1, int c2);


#endif