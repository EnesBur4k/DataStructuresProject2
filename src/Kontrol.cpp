/** 
* @file Kontrol.cpp
* @description IkiliAramaAgaci nesnesinin düğümlerinin eşit dağılıp dağılmadığını kontrol eder.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 25.12.2022
* @author enes.kaya11@ogr.sakarya.edu.tr
*/

#include "Kontrol.hpp"
using namespace std;

Kontrol::Kontrol()
{
    
}

Kontrol::~Kontrol()
{
    
}

int Height(DokuDugum *altDugum)
{
    if(altDugum == 0) return -1;
	return 1+max(Height(altDugum->sol),Height(altDugum->sag));
}
bool Kontrol::dengeliMi(IkiliAramaAgaci *bst)
{
    if( (bst->yukseklik(bst->kok->sol)) - 1 > (bst->yukseklik(bst->kok->sag)) )
    {
        return false;
    }
    if( (bst->yukseklik(bst->kok->sag)) - 1 > (bst->yukseklik(bst->kok->sol)) )
    {
        return false;
    }
    return true;
}