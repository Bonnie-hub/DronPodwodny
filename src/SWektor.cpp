#include"SWektor.hh"

template<class T, int SIZE>
SWektor<T, SIZE>::SWektor()
{
    ++Ilosc;
    OgolnaIlosc++;
    for (int i=0; i<Wymiar; i++)
    {
        dane[i] = 0.0;
    }
}

template<class T, int SIZE>
SWektor<T, SIZE>::SWektor(T *tab)
{
    ++Ilosc;
    OgolnaIlosc++;
    for (int i=0; i<Wymiar; i++)
    {
        dane[i] = tab[i];
    }
}

template<class T, int SIZE>
SWektor<T,SIZE>::SWektor(const SWektor & nowy)
{
    ++Ilosc;
    OgolnaIlosc++;
    for (int i=0; i<Wymiar; i++)
    {
        dane[i] = nowy.dane[i];
    }
}
/*
template<class T, int SIZE>
SWektor<T,SIZE>::SWektor(SWektor && nowy)
{
    ++Ilosc;
    for (int i=0; i<Wymiar; i++)
    {
        dane[i] = nowy.dane[i];
    }
}
*/
template<class T, int SIZE>
SWektor<T, SIZE>::~SWektor()
{
    --Ilosc;
}

template<class T, int SIZE>
T & SWektor<T, SIZE>::operator[] (int indeks)
{
    if(indeks >= 0 && indeks <= Wymiar - 1)
        return dane[indeks];
    else
    {
        std::cerr << "Indeks wykracza poza tablicę" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
const T & SWektor<T, SIZE>::operator[] (int indeks)const
{
    if(indeks >= 0 && indeks <= Wymiar - 1)
        return dane[indeks];
    else
    {
        std::cerr << "Indeks wykracza poza tablicę" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
SWektor<T, SIZE> SWektor<T, SIZE>::operator =(const T & W2)
{
    ++Ilosc;
    OgolnaIlosc++;
    for (int i=0; i<Wymiar; i++)
    {
        dane[i] = W2;
    }
    return *this;
}

template<class T, int SIZE>
SWektor<T, SIZE> SWektor<T, SIZE>::operator +(const SWektor<T,SIZE> & W2) const
{
    if(W2.Wymiar == Wymiar)
    {
        T *dodaj = new T[Wymiar];

        for(int i=0; i<Wymiar; i++)
        {
            dodaj[i] = 0;
            dodaj[i] = W2[i] + dane[i]; 
        }
    return SWektor(dodaj);
    }
    else
    {
        std::cout << "Wektory o innych wymiarach" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
SWektor<T, SIZE> SWektor<T, SIZE>::operator +=(const SWektor<T,SIZE> & W2)
{
    *this = *this + W2;
    return *this;
}

template<class T, int SIZE>
SWektor<T, SIZE> SWektor<T, SIZE>::operator -(const SWektor<T,SIZE> & W2) const
{
    if(W2.Wymiar == Wymiar)
    {
        T *odejmij = new T[Wymiar];

        for(int i=0; i<Wymiar; i++)
        {
            odejmij[i] = 0;
            odejmij[i] = dane[i] - W2[i]; 
        }
    return SWektor(odejmij);
    }
    else
    {
        std::cout << "Wektory o innych wymiarach" << std::endl;
        exit(1);
    }
}

template<class T, int SIZE>
SWektor<T, SIZE> SWektor<T, SIZE>::operator -=(const SWektor<T,SIZE> & W2)
{
    *this = *this - W2;
    return *this;
}

template<class T, int SIZE>
SWektor<T, SIZE> SWektor<T, SIZE>::operator *(const T & stala)const
{
    SWektor mnozenie;
    for(int i=0; i<Wymiar; i++)
    {
        mnozenie[i] = stala * dane[i];
    }
    return mnozenie;
}

template<class T, int SIZE>
int SWektor<T, SIZE>::Pobierz_Wymiar() const
{
    return Wymiar;
}

template<class T, int SIZE>
const T & SWektor<T, SIZE>::Pobierz_dane() const
{
    return *dane;
}

template<class T, int SIZE>
T SWektor<T, SIZE>::operator *(const SWektor & W2)const
{
    T skalar;
    skalar = 0.0;
    for (int i=0; i < Wymiar; i++)
    {
        skalar += W2[i]*dane[i];
    }
    return skalar;
}

template<class T,int SIZE>
bool SWektor<T,SIZE>::operator ==(const SWektor & W2)const
{
    for (int i=0; i<ROZMIAR; i++)
    {
        if(dane[i]!=W2.dane[i])
            return false;
    }
    return true;    
}

template<class T,int SIZE>
bool SWektor<T,SIZE>::operator !=(const SWektor & W2)const
{
    return !(*this==W2);
}

template<class T, int SIZE>
double SWektor<T,SIZE>::dlugosc() const
{
  double suma=0;
  for(int i=0; i<SIZE; i++)
  {
    suma+=pow(dane[i],2);
  }
  return sqrt(suma);
}

template<class T, int SIZE>
const drawNS::Point3D SWektor<T,SIZE>::P3D()const
{
    drawNS::Point3D point(dane[0],dane[1],dane[2]);
    return point;
}

template<class T, int SIZE>
int SWektor<T,SIZE>::AmountVector()
{
   return Ilosc;
}

template<class T, int SIZE>
int SWektor<T,SIZE>::AllAmountVector()
{
    return OgolnaIlosc;
}

template<class T, int SIZE>
std::istream& operator >> (std::istream &Strm, SWektor<T, SIZE> &Wek)
{
    
    for(int i=0; i<ROZMIAR; i++)
    {
        Strm >> Wek[i];
    }
    return Strm;
}

template<class T, int SIZE>
std::ostream& operator << (std::ostream &Strm, const SWektor<T, SIZE> &Wek)
{
    Strm << "|";
    for(int i=0; i<Wek.Pobierz_Wymiar(); i++)
    {
        if(i != Wek.Pobierz_Wymiar()-1)
            Strm << Wek[i] << " ";
        else
            Strm << Wek[i];
        
    }   
    Strm << "|";
    return Strm;
}