/** 
* @file Organ.cpp
* @description Doku nesnesini tutan düğümleri tutar.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 25.12.2022
* @author enes.kaya11@ogr.sakarya.edu.tr
*/

#include "Organ.hpp"
using namespace std;

Organ::Organ()
{

}

Organ::~Organ()
{

}

void Organ::ekle(Doku *dokuAdresi)
{
    bst->ekle(dokuAdresi);
}