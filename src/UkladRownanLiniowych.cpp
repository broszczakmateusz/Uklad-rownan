#include "UkladRownanLiniowych.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
std::istream &operator>>(std::istream &Strm, UkladRownanLiniowych &UklRown) {
    Macierz tmpA;
    Wektor tmpb;

    Strm >> tmpA;
    Strm >> tmpb;
    UklRown.set_A(tmpA);
    UklRown.set_b(tmpb);
    return Strm;
}

std::ostream &operator<<(std::ostream &Strm, const UkladRownanLiniowych &UklRown) {
    Strm << "Macierz A^T: " << std::endl;
    Strm << UklRown.get_A() << std::endl;
    Strm << "Wektor wyrazów wolnych b:" << std::endl;
    Strm << UklRown.get_b() << std::endl << std::endl;
    return Strm;
}

/*###########################################################*/

const Macierz &UkladRownanLiniowych::get_A() const {
    return A;
}

const Wektor &UkladRownanLiniowych::get_b() const {
    return b;
}

const Wektor &UkladRownanLiniowych::get_rozwiazanie() const {
    return rozwiazanie;
}

void UkladRownanLiniowych::set_A(const Macierz &AA) {
    A=AA;
}

void UkladRownanLiniowych::set_b(const Wektor &bb) {
    b=bb;
}
void UkladRownanLiniowych::set_rozwiazanie(const Wektor &Wynik) {
    rozwiazanie= Wynik;
}

/*###########################################################*/
//usunac transpozycje przy tmpA!!!!!11!
Wektor UkladRownanLiniowych::Oblicz() const {
    UkladRownanLiniowych UklWynikowy;
    Macierz  tmpA = get_A().transpozycja();
    Wektor tmpb = get_b();

    for (int i = 0; i < ROZMIAR; i++) {
        for (int j = i + 1; j < ROZMIAR; j++) {
            for (int k = 1; k < ROZMIAR; k++) {
                if (tmpA.tab[i][i] == 0) {
                    if (tmpA.tab[k][i] != 0) {
                        std::swap(tmpA.tab[i], tmpA.tab[k]);
                        std::swap(tmpb[i], tmpb[k]);

                        tmpb[j] = tmpb[j] - tmpb[i] * tmpA.tab[j][i] / tmpA.tab[i][i];
                        tmpA.tab[j] = tmpA.tab[j] - tmpA.tab[i] * tmpA.tab[j][i] / tmpA.tab[i][i];
                    }
                } else {
                    tmpb[j] = tmpb[j] - tmpb[i] * tmpA.tab[j][i] / tmpA.tab[i][i];
                    tmpA.tab[j] = tmpA.tab[j] - tmpA.tab[i] * tmpA.tab[j][i] / tmpA.tab[i][i];
                    break;
                }
            }
        }
    }

    Wektor Wynik;
    Wynik[ROZMIAR-1] = tmpb[ROZMIAR-1] / tmpA.tab[ROZMIAR-1][ROZMIAR-1];

    for (int i = ROZMIAR - 2; i >= 0; i--) {
        for (int j = ROZMIAR-1; j >= i+1; j--) {
            if (j == ROZMIAR-1 ) {
                Wynik[i] = (tmpb[i] - Wynik[j] * tmpA.tab[i][j] ) / tmpA.tab[i][i];
            } else {
                Wynik[i] = (tmpb[i] - (Wynik[j] * tmpA.tab[i][j] + Wynik[j + 1] * tmpA.tab[i][j + 1])) / tmpA.tab[i][i];
            }
        }
    }
    UklWynikowy.set_A(tmpA.transpozycja());
    UklWynikowy.set_b(tmpb);
    UklWynikowy.set_rozwiazanie(Wynik);

    return Wynik;
}




