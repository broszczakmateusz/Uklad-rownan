#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  Wektor W1(1,1,1);
  Wektor W2(2,2,2);
  Wektor W3(2,2,2);
  Macierz M1(W1,W2,W3);
  Macierz M2;
  //UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej

  cout << endl << " Start programu " << endl << endl;
  //cout << W1 << W2;
  cout << W1 + W2;
  cout << W1 - W2;
  cout << M2;



  return 0;
}

