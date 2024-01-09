/** 
* @file Sistem.cpp
* @description Organ nesnesini tutan OrganDugum nesnelerini tutar.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 25.12.2022
* @author enes.kaya11@ogr.sakarya.edu.tr
*/

#include "Sistem.hpp"
using namespace std;

Sistem::Sistem()
{
	ilkOrganDugum = 0;
	elemanSayisi = 0;
}

Sistem::~Sistem()
{

}

void Sistem::ekle(Organ *organAdresi)
{
    OrganDugum *yeniOrganDugum = new OrganDugum(organAdresi);
	if(ilkOrganDugum == 0)
		ilkOrganDugum = yeniOrganDugum;
	else
	{
		OrganDugum *gec = ilkOrganDugum;
		while(gec->sonraki != 0)
			gec = gec->sonraki;
		gec->sonraki = yeniOrganDugum;
	}
	elemanSayisi++;
}