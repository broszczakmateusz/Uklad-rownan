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

    Strm >> tmpA >> tmpb;
    UklRown.set_A(tmpA.transpozycja());
    UklRown.set_b(tmpb);

    return Strm;
}

std::ostream &operator<<(std::ostream &Strm, const UkladRownanLiniowych &UklRown) {
    Strm << UklRown.get_A() << UklRown.get_b();

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