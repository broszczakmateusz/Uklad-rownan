#include "Macierz.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
Macierz::Macierz() {
    for (int i = 0; i < ROZMIAR; i++) {
        Macierz::tab[i] = Wektor();
    }
}

Macierz::Macierz(Wektor Wie1, Wektor Wie2, Wektor Wie3) {

    Macierz::tab[0] = Wie1;
    Macierz::tab[1] = Wie2;
    Macierz::tab[2] = Wie3;
}

Wektor & Macierz::operator[] (int indeks) {
    if (indeks < 0 || indeks >= ROZMIAR) {
        std::cerr << "blad: zly indeks wektora";
        exit(1);
    }
    return this->tab[indeks];
}

const Wektor & Macierz::operator[] (int indeks) const {
    if (indeks < 0 || indeks >= ROZMIAR) {
        std::cerr << "blad: zly indeks wektora";
        exit(1);
    }
    return this->tab[indeks];
}


std::ostream& operator << (std::ostream &Strm, const Macierz &Mac) {
        for (int i = 0; i < ROZMIAR; i++) {
            Strm << Mac[i] << std::endl;
        }
    }

