#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Macierz {

    Wektor tab[ROZMIAR];
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */

  Macierz();
  Macierz(Wektor Wie1, Wektor Wie2, Wektor Wie3);

  const Wektor & operator[] (int indeks) const;
  Wektor & operator[] (int indeks);
  const double & operator() (int ind1, int ind2) const {return tab[ind1][ind2]; }
  double & operator() (int ind1, int ind2) {return tab[ind1][ind2]; }

  Macierz skopjuj() const;
  Macierz  transpozycja() const;
  Wektor  operator * (const Wektor & W) const;
};

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::istream& operator >> (std::istream &Strm, Macierz &Mac);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);


#endif
