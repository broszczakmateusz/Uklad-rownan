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
/*###########################################################*/
Wektor & Macierz::operator[] (int indeks) {
    if (indeks < 0 || indeks >= ROZMIAR) {
        std::cerr << "blad: zly indeks macierzy";
        exit(1);
    }
    return this->tab[indeks];
}

const Wektor & Macierz::operator[] (int indeks) const {
    if (indeks < 0 || indeks >= ROZMIAR) {
        std::cerr << "blad: zly indeks macierzy";
        exit(1);
    }
    return this->tab[indeks];
}

std::istream & operator >> (std::istream &Strm, Macierz &Mac) {
    Wektor Wie1, Wie2, Wie3;
    Strm >> Wie1;
    Strm >> Wie2;
    Strm >> Wie3;

    Macierz tmp( Wie1, Wie2, Wie3);
    Mac = tmp;

    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac) {
        for (int i = 0; i < ROZMIAR; i++) {
            Strm << Mac[i] << std::endl;
        }
    return Strm;
}
/*###########################################################*/
/* Tworzy kopie macierzy*/
Macierz Macierz::skopjuj() const {
    Macierz kopia;

    for (int i = 0; i<ROZMIAR; i++) {
        kopia.tab[i] = tab[i];
    }
    return kopia;
}
/* Transponuje macierz*/
Macierz Macierz::transpozycja() const {
    Macierz Transponowana, tmp;

    tmp = Macierz::skopjuj();

    for (int i = 0; i<ROZMIAR; i++) {
        for (int j = 0; j<ROZMIAR; j++) {
            Transponowana.tab[i][j] = tmp.tab[j][i];
        }
    }
    return Transponowana;
}

/* Iloczyn Macierzy i wektora. Zwraca wektor */
Wektor Macierz::operator*(const Wektor &W) const {
    Wektor Wynikowy;

    for (int i = 0; i<ROZMIAR; i++) {
        for (int j = 0; j<ROZMIAR; j++) {
            Wynikowy[i] += W[j] * tab[i][j];
        }
    }
    return Wynikowy;
}
