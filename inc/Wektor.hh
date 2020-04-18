#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Wektor {

    double dane[ROZMIAR];

    public:
        Wektor();
        Wektor(double x, double y, double z); //konstruktor od kolekcji

        const double & operator[] (int indeks) const;
        double & operator[] (int indeks);

        Wektor operator + (const Wektor & W2) const;
        Wektor operator - (const Wektor & W2) const;
        double operator * (const Wektor & W2) const;

        Wektor  operator * (  double liczba) const;
        Wektor  operator / (  double liczba) ;
        double dlugosc() const;
    };

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream & Strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */

std::ostream& operator << (std::ostream & Strm, const Wektor & Wek);


#endif
