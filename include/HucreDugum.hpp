#ifndef HucreDugum_hpp
#define HucreDugum_hpp
#include "Hucre.hpp"

class HucreDugum
{
    public:
        Hucre *hucreAdresi;
        HucreDugum *sonraki;
    
    public:
        HucreDugum(Hucre *hucreAdresi);
        ~HucreDugum();
};

#endif