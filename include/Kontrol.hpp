#ifndef Kontrol_hpp
#define Kontrol_hpp

#include "IkiliAramaAgaci.hpp"

class Kontrol
{
    private:
    IkiliAramaAgaci *bst;
    public:
        Kontrol();
        ~Kontrol();

        int yukseklik(IkiliAramaAgaci *bst);
        bool dengeliMi(IkiliAramaAgaci *bst);
};

#endif