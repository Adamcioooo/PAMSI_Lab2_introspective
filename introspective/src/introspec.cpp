#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <new>
#include "introspec.hh"
using namespace std;

//Funkcja zaraca liosc wierszy
int policz(string nazwa){

	string str;				//Zmienna pomocnicza
	int zakres = 0;			//Zmienna zliczajaca ilosc wierszy

	fstream filmy;
	filmy.open(nazwa);		//Otwarcie pliku

	while(!filmy.eof()){	//Petla dziala tak dlugo az nie natrafi na ostatni wiersz
		getline(filmy,str);	//Przypisanie wartosci wiersza do zmiennej pomocniczej
		zakres++;			//Zwiekszenie zakresu
	}
	filmy.close();			//Zamkniecie pliku
	return zakres;			//Zwraca ilosc wierszy
}



//Funkcaj usuwa wiersze z pustymi kolumnami
int usun_zbedne(Filmy *filmiki,string nazwa_pliku){



	fstream filmy;
	filmy.open(nazwa_pliku);		//Otwarcie pliku
	string wiersz;					//Zmienna pomocnicza
	int i = 0;						//Zmienna pomocnicza
	char delim = ';';				//Zmienna pomocnicza



	while(i < 10000){			//Petla dziala tak dlugo az nie natrafi na ostatni wiersz

			getline(filmy,wiersz, delim);		//Wczytywanie wiersza do znaku
			getline(filmy,wiersz, delim);		//Wczytywanie tego samego wiersza az do znaku
			filmiki[i].tytul = wiersz;			//Podstawia nazwe tytulu pod zmienna tytul

			getline(filmy,wiersz);				//Wczytywanie tego samego wiersza az do znaku
			filmiki[i].ocena = atof(wiersz.c_str());	//Wczytanie oceny i zmiana stringa na float
			if(filmiki[i].ocena == '\0'){				//Sprawdzenie czy nie ma pustego pola
				i--;									//Jezeli jest puste pole wczytuje kolejny wiersz nadpisujac stary
			}
			i++;										//Zwiekszenie zakresu

		}
	return i;											//Zwraca ilosc wierszy po usunieciu niektorych pozycji
}

//Sprawdza poprawnosc sortowania
void sprawdz(Filmy *filmiki, int i){

	int j = 1;											//Zmienna pomocnicza

	while(j < i){											//Petla dziala tak dlugo az dojdzie do ostatniego wiersza
	    if(filmiki[j-1].ocena > filmiki[j].ocena){			//Porowanienie poprzedniego i obecnego elementu
	    	cout << "NIE UDALO SIE POSORTOWAC!!!" << endl;	//Zwraca ostrzezenie
	    }
	    j++;												//Zwiekszenie zakresu

	 }

}

//Funkcja zapisuje posortowanie wiersze do pliku
void zapisz(Filmy *filmiki, int i){

	int j = 0;				//Zmienna pomocnicza
	string nowy_plik;		//Zmienna przechowujac anazwe nowego pliku
	ofstream wyjscie;

	cout << "Podaj nazwe pliku: ";
	cin >>  nowy_plik;				//Zapisanie nazwy nowego pliku
	wyjscie.open(nowy_plik);		//Ustawienie jako wyjscie

	while(j < i){					//Petla dziala tak dlugo az dojdzie do ostatniego wiersza
									//Wpisywanie do pliku odpowiednich wartosci
		wyjscie  << j << "," << filmiki[j].tytul << ", " << filmiki[j].ocena << ".0" << endl;
	    j++;						//Zwiekszenie zakresu
	}
	wyjscie.close();				//Zamyka plik
}

//Funkcja sortuje dane
void insertsort(Filmy * filmiki, int l, int r){



	for (int i = l + 1; i <= r; i++)				//Pêtla dziala tak dlugo az dojdzie do konca zakresu
	{
		Filmy a = filmiki[i];						//Przypisanie i-tego wiersza do nowej zmiennej tymczasowej
		int j = i;									//Zmienna pomocnicza

		while (j > l && filmiki[j - 1].ocena > a.ocena)		//Petla dziala tak dlugo az j bedzie rowne l lub wartosc j-1 wiersza bedzie mniejsze od zmiennej tymczasowej
        {
            filmiki[j] = filmiki[j - 1];					//Podstawienie poprzedniego wiersza pod aktualny
            j--;											//Zmniejszenie zakresu
        }
		filmiki[j] = a;										//Podstawienie zmiennej tymczasowej

	}

}



























