#ifndef USER_H
#define USER_H

// Funkcja odpowiadaj�ca za to, �eby u�ytkownik poda� prawid�owe dane (zabezpiecza przed wpisaniem innych znak�w ni� cyfry)
int getNumber();

// Funkcja odpowiadaj�ca za wpisywanie przez u�ytkownika danych p�l, kt�re chce odkry�,
//posiada zabezpieczenie przed podaniem za ma�ych lub za du�ych warto�ci
void chosing(int *row1, int *row2, int *column1, int *column2, int row, int column);

// Funkcja odpowiadaj�ca za pobranie od u�ytkownika wymiar�w planszy
void takeData(int *f_row, int *f_col);
#endif