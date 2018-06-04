#ifndef UTILITY_H
#define UTILITY_H

//Funkcja wpisuje statystyki do pliku, po skoñczonej grze nie nadpisuje pliku,
//tylko dodaje nowe dane na jego koniec
void file(int row, int column, int moves);


//funkcja opó¿niaj¹ca przechodzenie do nastêpnej czynnoœci
void delay(int sec);


//funkcja zwalniaj¹ca pamiêæ dwuwymiarowych tablic dynamicznych
void free_memory(int **tab, int col);


#endif