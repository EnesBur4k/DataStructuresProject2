/** 
* @file OrganDugum.cpp
* @description Organ nesnesini tutar.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 25.12.2022
* @author enes.kaya11@ogr.sakarya.edu.tr
*/

#include "OrganDugum.hpp"
using namespace std;

OrganDugum::OrganDugum(Organ *organAdresi)
{
    this->organAdresi = organAdresi;
    this->sonraki = 0;
}

OrganDugum::~OrganDugum()
{

}