#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {

    Macierz A;
    Wektor b;
    Wektor rozwiazanie;
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  public:
    UkladRownanLiniowych() {};
    UkladRownanLiniowych(Macierz AA, Wektor bb) : A(AA), b(bb) {};

    const Macierz & get_A() const;
    const Wektor & get_b() const;
    void set_A(const Macierz & AA);
    void set_b(const Wektor & bb);
    void set_rozwiazanie(const Wektor & Wynik);
    const Wektor & get_rozwiazanie() const;
    Wektor Oblicz() const;

};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown);


#endif
