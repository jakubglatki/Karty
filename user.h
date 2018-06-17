#ifndef USER_H
#define USER_H

// Funkcja odpowiadaj¹ca za to, ¿eby u¿ytkownik poda³ prawid³owe dane (zabezpiecza przed wpisaniem innych znaków ni¿ cyfry)
int getNumber();

// Funkcja odpowiadaj¹ca za wpisywanie przez u¿ytkownika danych pól, które chce odkryæ,
//posiada zabezpieczenie przed podaniem za ma³ych lub za du¿ych wartoœci
void chosing(int *row1, int *row2, int *column1, int *column2, int row, int column);

// Funkcja odpowiadaj¹ca za pobranie od u¿ytkownika wymiarów planszy
void takeData(int *f_row, int *f_col);
#endif