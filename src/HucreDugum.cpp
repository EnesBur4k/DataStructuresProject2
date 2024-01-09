/** 
* @file HucreDugum.cpp
* @description Hucre nesnesini tutar.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 25.12.2022
* @author enes.kaya11@ogr.sakarya.edu.tr
*/

#include "HucreDugum.hpp"
using namespace std;

HucreDugum::HucreDugum(Hucre *hucreAdresi)
{
    this->hucreAdresi = hucreAdresi;
    this->sonraki = 0;
}

HucreDugum::~HucreDugum()
{
    delete hucreAdresi;
}