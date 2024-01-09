/** 
* @file SistemDugum.cpp
* @description Sistem nesnesini tutar.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 25.12.2022
* @author enes.kaya11@ogr.sakarya.edu.tr
*/

#include "SistemDugum.hpp"
using namespace std;

SistemDugum::SistemDugum(Sistem *sistemAdresi)
{
    this->sistemAdresi = sistemAdresi;
    this->sonraki = 0;
}

SistemDugum::~SistemDugum()
{

}