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
    double x=0, y=0, z=0;
    Strm >> x >> y >> z;
    Wektor tmp( x, y, z);
    Wek = tmp;

    return Strm;
}

std::ostream & operator << (std::ostream &Strm, const Wektor &Wek) {
    for (int i = 0; i < ROZMIAR; i++) {
        Strm << Wek[i] << " ";
    }
    return Strm;
}

/*###########################################################*/
/* Suma dwóch wektrów*/
Wektor Wektor::operator + (const Wektor & W2) const {
    Wektor Wynikowy;
    for (int i = 0; i < ROZMIAR; i++)
        Wynikowy[i] =  dane[i] + W2.dane[i] ;

    return Wynikowy;
}

/* Różnica dwóch wektrów*/
Wektor Wektor::operator - (const Wektor &W2) const {
    Wektor Wynikowy;
    for (int i = 0; i < ROZMIAR; i++)
        Wynikowy[i] =  dane[i] - W2.dane[i] ;

    return Wynikowy;
}

/* Iloczyn skalarny dwóch wektorów*/
double Wektor::operator * (const Wektor &W2) const {
    double Wynik = 0;
    for (int i = 0; i < ROZMIAR; i++)
        Wynik += dane[i] * W2.dane[i];

    return Wynik;
}
/*###########################################################*/
/* Iloczyn Wektor * liczba */
Wektor Wektor::operator * (double liczba)  {
    Wektor Wynikowy;
    for (int i = 0; i < ROZMIAR; i++)
        Wynikowy.dane[i] = dane[i] * liczba;

    return Wynikowy;
}
/* Iloraz Wektor / liczba */
Wektor Wektor::operator / (double liczba)  {
    Wektor Wynikowy;
    for (int i = 0; i < ROZMIAR; i++)
        Wynikowy.dane[i] = dane[i] / liczba;

    return Wynikowy;
}
/*###########################################################*/
/* Metoda licząca długość wektora */
double Wektor::dlugosc() const {
    double Wynik = 0;
    for (int i = 0; i < ROZMIAR; i++)
        Wynik = Wynik + dane[i] * dane[i];

    return Wynik;
}