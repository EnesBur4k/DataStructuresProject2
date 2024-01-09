/** 
* @file Organizma.cpp
* @description Sistem nesnesini tutan SistemDugumu nesnelerini tutar.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 25.12.2022
* @author enes.kaya11@ogr.sakarya.edu.tr
*/

#include "Organizma.hpp"
using namespace std;

Organizma::Organizma()
{

}

Organizma::~Organizma()
{

}

void Organizma::sistemEkle(Sistem *sistemAdresi)
{
    SistemDugum *yeniSistemDugum = new SistemDugum(sistemAdresi);
	if(ilkSistemDugum == 0)
		ilkSistemDugum = yeniSistemDugum;
	else
	{
		SistemDugum *gec = ilkSistemDugum;
		while(gec->sonraki != 0)
			gec = gec->sonraki;
		gec->sonraki = yeniSistemDugum;
	}
}