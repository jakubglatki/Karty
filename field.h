#ifndef FIELD_H
#define FIELD_H

// Funkcja odpowiadaj¹ca za wylosowanie poszczególnych wartoœci pól na planszy
void shuffle(int **field, int row, int column);

// Funkcja odpowiadaj¹ca za wypisanie pola gry, które ró¿ni siê w zale¿noœci
// od zaawansowania danej rozgrywki
void printField(int row, int column, int **status, int **field, int r1, int r2, int c1, int c2);


#endif