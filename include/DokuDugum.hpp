#ifndef DokuDugum_hpp
#define DokuDugum_hpp
#include "Doku.hpp"

class DokuDugum
{
public:
    Doku *dokuAdresi;
    DokuDugum* sol = 0;
    DokuDugum* sag = 0;
    
    DokuDugum(Doku *dokuAdresi);
    ~DokuDugum();
};

#endif