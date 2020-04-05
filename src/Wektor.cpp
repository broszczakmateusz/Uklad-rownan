#include "Wektor.hh"
#include <iostream>


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
Wektor::Wektor() {
    for (int i = 0; i < ROZMIAR; i++) {
        Wektor::dane[i] = 0;
    }
}

Wektor::Wektor(double x, double y, double z) {

    Wektor::dane[0] = x;
    Wektor::dane[1] = y;
    Wektor::dane[2] = z;
}

double & Wektor::operator[] (int indeks) {
if (indeks < 0 || indeks >= ROZMIAR) {
std::cerr << "blad: zly indeks wektora";
exit(1);
}
return this->dane[indeks];
}

const double & Wektor::operator[] (int indeks) const {
    if (indeks < 0 || indeks >= ROZMIAR) {
        std::cerr << "blad: zly indeks wektora";
        exit(1);
    }
    return this->dane[indeks];
}

std::istream & operator >> (std::istream & Strm, Wektor &Wek) {
    double x, y, z;
    Strm >> x >> y >> z;
    Wektor( x, y, z);
}

std::ostream & operator << (std::ostream &Strm, const Wektor &Wek) {
    for (int i = 0; i < ROZMIAR; i++) {
        Strm << Wek[i] << " ";
    }
}

const Wektor &Wektor::operator+(const Wektor & W2) const {
 Wektor Wynikowy;
    for (int i = 0; i < ROZMIAR; i++)
        Wynikowy.dane[i] = dane[i] + W2.dane[i];

return Wynikowy;
}

const Wektor &Wektor::operator-(const Wektor &W2) const {
 Wektor Wynikowy;
    for (int i = 0; i < ROZMIAR; i++)
        Wynikowy.dane[i] = dane[i] - W2.dane[i];

return Wynikowy;
}
double Wektor::operator * (const Wektor &W2) const {
    double Wynik = 0;
    for (int i = 0; i < ROZMIAR; i++)
        Wynik += dane[i] * W2.dane[i];

    return Wynik;
}

double Wektor::dlugosc() const {
 double Wynik = 0;
     for (int i = 0; i < ROZMIAR; i++) {
       Wynik = Wynik + dane[i] * dane[i];
    }
    return Wynik;
}

