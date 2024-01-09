#ifndef OrganDugum_hpp
#define OrganDugum_hpp
#include "Organ.hpp"
using namespace std;

class OrganDugum
{
    public:
        Organ *organAdresi;
        OrganDugum *sonraki;
    
    public:
        OrganDugum(Organ *organAdresi);
        ~OrganDugum();
};

#endif