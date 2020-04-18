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
    UklRown.set_A(tmpA.transpozycja());
    UklRown.set_b(tmpb);

    return Strm;
}

std::ostream &operator<<(std::ostream &Strm, const UkladRownanLiniowych &UklRown) {
    Strm << UklRown.get_A().transpozycja() << UklRown.get_b();

    return Strm;
}

/*###########################################################*/

const Macierz &UkladRownanLiniowych::get_A() const {
    return A;
}

const Wektor &UkladRownanLiniowych::get_b() const {
    return b;
}

void UkladRownanLiniowych::set_A(const Macierz &AA) {
    A=AA;
}

void UkladRownanLiniowych::set_b(const Wektor &bb) {
    b=bb;
}


/*###########################################################*/

Wektor UkladRownanLiniowych::Oblicz() const {
    Macierz  tmpA = get_A();
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

    return tmpb;
}
