/** 
* @file Doku.cpp
* @description Hucre nesnesini tutan HucreDugum nesnelerini tutar.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 25.12.2022
* @author enes.kaya11@ogr.sakarya.edu.tr
*/

#include "Doku.hpp"
using namespace std;

Doku::Doku()
{
	ilkHucreDugum = 0;
	elemanSayisi = 0;
}

Doku::~Doku()
{
	HucreDugum *gec = ilkHucreDugum;
	HucreDugum *silinecek;
	while(gec != 0)
	{
		silinecek = gec;
		gec = gec->sonraki;
		delete silinecek;
	}
}

void Doku::hucreEkle(Hucre *hucreAdresi)
{
	HucreDugum *yeniHucreDugum = new HucreDugum(hucreAdresi);
	if(ilkHucreDugum == 0)
		ilkHucreDugum = yeniHucreDugum;
	else
	{
		HucreDugum *gec = ilkHucreDugum;
		while(gec->sonraki != 0)
			gec = gec->sonraki;
		gec->sonraki = yeniHucreDugum;
	}
	elemanSayisi++;
}

Hucre* Doku::ortaHucre()
{
	HucreDugum *gec = ilkHucreDugum;
	for(double i = 0; i < elemanSayisi/2; i++)
		gec = gec->sonraki;
	return gec->hucreAdresi;
}

int Doku::dokuDegeri()
{
	return ortaHucre()->dnaUzunlugu;
}
