#include "Macierz.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
Macierz::Macierz() {
    for (int i = 0; i < ROZMIAR; i++) {
        Macierz::tab[i] = Wektor();
    }
}

Macierz::Macierz(Wektor Wie1, Wektor Wie2, Wektor Wie3) {

    Macierz::tab[0] = Wie1;
    Macierz::tab[1] = Wie2;
    Macierz::tab[2] = Wie3;
}
/*###########################################################*/
Wektor & Macierz::operator[] (int indeks) {
    if (indeks < 0 || indeks >= ROZMIAR) {
        std::cerr << "blad: zly indeks macierzy";
        exit(1);
    }
    return this->tab[indeks];
}

const Wektor & Macierz::operator[] (int indeks) const {
    if (indeks < 0 || indeks >= ROZMIAR) {
        std::cerr << "blad: zly indeks macierzy";
        exit(1);
    }
    return this->tab[indeks];
}

const Wektor &Macierz::get_wiersz(int indeks) const {
    return this->tab[indeks];
}

void Macierz::set_wiersz(const Wektor &bb){
   // get_wiersz();
   // tab = bb;
}

std::istream & operator >> (std::istream &Strm, Macierz &Mac) {
    Wektor Wie1, Wie2, Wie3;
    Strm >> Wie1;
    Strm >> Wie2;
    Strm >> Wie3;

    Macierz tmp( Wie1, Wie2, Wie3);
    Mac = tmp;

    return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac) {
        for (int i = 0; i < ROZMIAR; i++) {
            Strm << Mac[i] << std::endl;
        }
    return Strm;
}
/*###########################################################*/
/* Tworzy kopie macierzy*/
Macierz Macierz::skopjuj() const {
    Macierz kopia;

    for (int i = 0; i<ROZMIAR; i++) {
        kopia.tab[i] = tab[i];
    }
    return kopia;
}
/* Transponuje macierz*/
Macierz Macierz::transpozycja() const {
    Macierz Transponowana, tmp;

    tmp = Macierz::skopjuj();

    for (int i = 0; i<ROZMIAR; i++) {
        for (int j = 0; j<ROZMIAR; j++) {
            Transponowana.tab[i][j] = tmp.tab[j][i];
        }
    }
    return Transponowana;
}

/* Iloczyn Macierzy i wektora. Zwraca wektor */
Wektor Macierz::operator*(const Wektor &W) const {
    Wektor Wynikowy;

    for (int i = 0; i<ROZMIAR; i++) {
        for (int j = 0; j<ROZMIAR; j++) {
            Wynikowy[i] += W[j] * tab[i][j];
        }
    }
    return Wynikowy;
}




double Macierz::wyznacznik() const {
    Macierz  tmp = Macierz::skopjuj();
    double det = 1;
    int przestW = 0;

        for (int i = 0; i < ROZMIAR; i++) {
            for (int j = i + 1; j < ROZMIAR; j++) {
                for (int k = 1; k < ROZMIAR; k++) {
                    if (tmp.tab[i][i] == 0) {
                        if (tmp.tab[k][i] != 0) {

                        std::swap(tmp.tab[i], tmp.tab[k]);
                        przestW++;
                            std::cout << tmp << std::endl;
                        tmp.tab[j] = tmp.tab[j] - tmp.tab[i] * tmp.tab[j][i] / tmp.tab[i][i];
                        std::cout << j << ".j" << std::endl;
                        std::cout << tmp << std::endl;
                        }

                    } else {

                        tmp.tab[j] = tmp.tab[j] - tmp.tab[i] * tmp.tab[j][i] / tmp.tab[i][i];
                        std::cout << j << ".j" << std::endl;
                        std::cout << tmp << std::endl;
                    }
                }
            }
        }
    for( int i = 0; i<ROZMIAR; i++) {
        det *=  tmp.tab[i][i];
    }
    std::cout << przestW <<std::endl;
    if (przestW % 2)
        return -det;
    else
        return det;
}


/*
 *
 *
 * double Macierz::wyznacznik() const {
    //tmp.tab[j][k] = tmp.tab[j][k] - (tab[j][i] / tab[i][i] * tab[i][k]);
    Macierz  tmp;
    double m = tab[0][0] ; //mnożnik

    tmp = Macierz::skopjuj();
    //tmp.tab[0] = tmp.tab[0] / m;
    /*for(int i=0; i<ROZMIAR; i++) {
        tmp.tab[i] = tmp.tab[i] / m;

    }
std::cout << tmp<<"po podzelieiu"<<std::endl;
for(int i=0; i < ROZMIAR; i++) {
for (int j = i+1; j < ROZMIAR; j++) {
//for(int k = i+1; k < ROZMIAR; k++) {
tmp.tab[j] = tmp.tab[j] - tmp.tab[i] * tmp.tab[j][i]/ tmp.tab[i][i];
std::cout << j << ".j" << std::endl;
std::cout << tmp << std::endl;

//tmp.tab[k] = tmp.tab[k] - tmp.tab[k-1] * tmp.tab[k][k-1] / tmp.tab[k-1][k-1];
//std::cout << k << ".k" << std::endl;
//std::cout << tmp << std::endl;
//}
}
}

double det=1;
for( int i=0;i<ROZMIAR;i++) {
det = det * tmp.tab[i][i];
}
std::cout << det <<std::endl;

return det;
}*/
/*
double Macierz::wyznacznik() const {
    //tmp.tab[j][k] = tmp.tab[j][k] - (tab[j][i] / tab[i][i] * tab[i][k]);
    Macierz  tmp;
    double m = tab[0][0] ; //mnożnik

    tmp = Macierz::skopjuj();
    for(int i=0; i<ROZMIAR; i++) {
        tmp.tab[i] = tmp.tab[i] / m;

    }
    std::cout << tmp<<"po podzelieiu"<<std::endl;
    for(int i=1; i<ROZMIAR; i++) {

        tmp.tab[i] = tmp.tab[i] - tmp.tab[0] * tmp.tab[i][0];
        std::cout << i<<".i"<<std::endl;
        std::cout << tmp<<std::endl;

    }
    for(int j=2; j < ROZMIAR; j++) {

        tmp.tab[j] = tmp.tab[j] - tmp.tab[j-1] * tmp.tab[j][j-1] / tmp.tab[j-1][j-1];
        std::cout << j<<".j"<<std::endl;
        std::cout << tmp<<std::endl;
        //for(int k=i+1; k < ROZMIAR; k++) {


    }

    double det=1;
    for( int i=1;i<ROZMIAR;i++) {
        det = det * tmp.tab[i][i];
    }
    det = det * m;
    std::cout << det<<std::endl;

    return det;
}*/
/*
double Macierz::wyznacznik() const {
    //tmp.tab[j][k] = tmp.tab[j][k] - (tab[j][i] / tab[i][i] * tab[i][k]);
    Macierz  tmp;
    double m = tab[0][0] ; //mnożnik

    tmp = Macierz::skopjuj();
    for(int i=0; i<ROZMIAR; i++) {
        tmp.tab[i] = tmp.tab[i] / m;

    }
    std::cout << tmp<<"po podzelieiu"<<std::endl;
    for(int i=1; i<ROZMIAR; i++) {
        for (int j = 2; j < ROZMIAR; j++) {

            tmp.tab[i] = tmp.tab[i] - tmp.tab[0] * tmp.tab[i][0];
            std::cout << i << ".i" << std::endl;
            std::cout << tmp << std::endl;

            tmp.tab[j] = tmp.tab[j] - tmp.tab[j - 1] * tmp.tab[j][j - 1] / tmp.tab[j - 1][j - 1];
            std::cout << j << ".j" << std::endl;
            std::cout << tmp << std::endl;
            //for(int k=i+1; k < ROZMIAR; k++) {


        }
    }

    double det=1;
    for( int i=1;i<ROZMIAR;i++) {
        det = det * tmp.tab[i][i];
    }
    det = det * m;
    std::cout << det<<std::endl;

    return det;
}*/