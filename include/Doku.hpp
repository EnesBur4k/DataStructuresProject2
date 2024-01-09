#ifndef Doku_hpp
#define Doku_hpp
#include "HucreDugum.hpp"

class Doku
{
    public:
        HucreDugum *ilkHucreDugum;
        double elemanSayisi;
    
    public:
        Doku();
        ~Doku();
        void hucreEkle(Hucre *hucreAdresi);
        Hucre* ortaHucre();
        int dokuDegeri();
};

#endif