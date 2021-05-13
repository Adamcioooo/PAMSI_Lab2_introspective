#ifndef INTROSPEC_HH
#define INTROSPEC_HH
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
#include <new>
using namespace std;


				//Struktura Filmy
				//zawiera string tytul który przechowuje nazwe filmu
				// float ocena przechowuje ocene filmy

struct Filmy {
    string tytul;
    float ocena;

};

//Funkcja zwraca ilosc wierszy w pliku
int policz(string nazwa);

//Funkcja usuwa puste pola
int usun_zbedne(Filmy *filmiki,string nazwa_pliku);

//Funkcaj sprwdza czy sortowanie powiodlo sie
void sprawdz(Filmy *filmiki, int i);

//Funkcja zapisuje do pliku
void zapisz(Filmy *filmiki, int i);

//Funkcja sortuje dane
void insertsort(Filmy * filmiki, int left, int right);





















#endif
