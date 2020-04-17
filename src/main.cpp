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
  Wektor W1(0,1,2);
  Wektor W2(10,11,12);
  Wektor W3(20 ,21,22);
  Wektor W4(0,0,0);
  Macierz M1(W1,W2,W3);
  Macierz M2;
  //UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej

  cout << endl << " Start programu " << endl << endl;
  //cout << W1 << W2;
 //cin >> M2;
    cout << M1<<endl;
 cout << M1 * W4;

  return 0;
}

