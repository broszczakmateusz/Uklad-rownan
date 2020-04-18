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
  Wektor W1(5,1,1);
  Wektor W2(-1,1,1);
  Wektor W3(3 ,2,3);
  Wektor W4(7,4,3);
  Macierz M1(W1,W2,W3);
  Macierz M2;
  UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej

  cout << endl << " Start programu " << endl << endl;
  //cout << W1 << W2;
 //cin >> UklRown;
    cout << M1<<endl;

 cout << M1.wyznacznik();

  return 0;
}

