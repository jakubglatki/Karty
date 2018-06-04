#ifndef UTILITY_H
#define UTILITY_H

//Funkcja wpisuje statystyki do pliku, po sko�czonej grze nie nadpisuje pliku,
//tylko dodaje nowe dane na jego koniec
void file(int row, int column, int moves);


//funkcja op�niaj�ca przechodzenie do nast�pnej czynno�ci
void delay(int sec);


//funkcja zwalniaj�ca pami�� dwuwymiarowych tablic dynamicznych
void free_memory(int **tab, int col);


#endif