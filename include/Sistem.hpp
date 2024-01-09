#ifndef Sistem_hpp
#define Sistem_hpp
#include "OrganDugum.hpp"

class Sistem
{
    public:
        OrganDugum *ilkOrganDugum;
        int elemanSayisi;
    
    public:
        Sistem();
        ~Sistem();
        void ekle(Organ *organAdresi);

};

#endif