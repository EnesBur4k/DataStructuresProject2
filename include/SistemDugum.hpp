#ifndef SistemDugum_hpp
#define SistemDugum_hpp
#include "Sistem.hpp"

class SistemDugum
{
    public:
        Sistem *sistemAdresi;
        SistemDugum *sonraki;
    
    public:
        SistemDugum(Sistem *sistemAdresi);
        ~SistemDugum();
};

#endif