#include <iostream>
#include "Wektor.hh"
#include "UkladRownanLiniowych.hh"

using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{/* Wektor W1(2,1,1);
  Wektor W2(2,2,3);
  Wektor W3(1 ,1.5,1);
  Wektor W4(9,8.5,8);
  Macierz M1(W1,W2,W3);*/

  UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej
    Wektor Wx;
    Wektor Wbledu;

    cout << endl << "Start programu " << endl << endl;
    cin >> UklRown;
    cout <<endl<< UklRown;

    cout << "Rozwiazanie x = (x1, x2, x3):" << endl;
    Wx = UklRown.Oblicz();
    cout << Wx << endl;

    Wbledu = UklRown.get_A().transpozycja() * Wx - UklRown.get_b();
    cout << "Wektor bledu: Ax-b = " << Wbledu << endl;
    cout << "Dlugosc wektora bledu: ||Ax-b|| = " << Wbledu.dlugosc();

    return 0;
}

