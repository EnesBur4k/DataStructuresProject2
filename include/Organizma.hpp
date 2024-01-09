#ifndef Organizma_hpp
#define Organizma_hpp
#include "SistemDugum.hpp"

class Organizma
{
    public:
        SistemDugum *ilkSistemDugum = 0;

    public:
        Organizma();
        ~Organizma();
        void sistemEkle(Sistem *sistemAdresi);
};

#endif