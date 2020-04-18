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

  Wektor W1(2,1,1);
  Wektor W2(2,2,3);
  Wektor W3(1 ,1.5,1);
  Wektor W4(9,8.5,8);
  Macierz M1(W1,W2,W3);
  Macierz M2;
  UkladRownanLiniowych   UklRown(M1,W4);   // To tylko przykladowe definicje zmiennej

  cout << endl << " Start programu " << endl << endl;
  //cout << W1 << W2;
 //cin >> UklRown;
    //cout << M2<<endl;

 cout << UklRown.Oblicz();

  return 0;
}

