#ifndef Organ_hpp
#define Organ_hpp
#include "Doku.hpp"
#include "IkiliAramaAgaci.hpp"

class Organ
{
    public:
        IkiliAramaAgaci *bst = new IkiliAramaAgaci();
    public:
        Organ();
        ~Organ();
        void ekle(Doku *doku);
};

#endif