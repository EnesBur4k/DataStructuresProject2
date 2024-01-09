/** 
* @file IkiliAramaAgaci.cpp
* @description Organda tutulacak ikili arama ağacı nesnesini oluşturur.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 25.12.2022
* @author enes.kaya11@ogr.sakarya.edu.tr
*/

#include "IkiliAramaAgaci.hpp"
using namespace std;

IkiliAramaAgaci::IkiliAramaAgaci()
{
    kok = 0;
    dokuSayac = 0;
}

IkiliAramaAgaci::~IkiliAramaAgaci()
{
    
}

bool IkiliAramaAgaci::bosMu()const
{
    return kok == 0;
}

void IkiliAramaAgaci::araVeEkle(DokuDugum *&altDugum, Doku *dokuAdresi)
{
    if(altDugum == 0)
    {
        DokuDugum *yeniDokuDugum = new DokuDugum(dokuAdresi);
        altDugum = yeniDokuDugum;
        return;
    }
    if(dokuAdresi->dokuDegeri() <= altDugum->dokuAdresi->dokuDegeri())
    {
        araVeEkle(altDugum->sol, dokuAdresi);
    }
    if(dokuAdresi->dokuDegeri() > altDugum->dokuAdresi->dokuDegeri())
    {
        araVeEkle(altDugum->sag, dokuAdresi);
    }
}

void IkiliAramaAgaci::ekle(Doku *dokuAdresi)
{
    araVeEkle(kok, dokuAdresi);
}

void IkiliAramaAgaci::sifirlaIslemleri(DokuDugum *altDugum)
{
    if(altDugum == 0) return;
    sifirlaIslemleri(altDugum->sol);
    sifirlaIslemleri(altDugum->sag);
    delete altDugum;
}

void IkiliAramaAgaci::sifirla()
{
    sifirlaIslemleri(kok);
    kok = 0;
}

int IkiliAramaAgaci::yukseklik(DokuDugum *altDugum)
{
    if(altDugum == 0) return -1;
	return 1 + max(yukseklik(altDugum->sol), yukseklik(altDugum->sag));
}

void IkiliAramaAgaci::mutasyonIslemleri(DokuDugum *altDugum)
{
    if(altDugum == 0) return;
    int hucreSayac = 0;
    dokuSayac++;
    mutasyonIslemleri(altDugum->sol);
    mutasyonIslemleri(altDugum->sag);
   
    HucreDugum *gecHucreDugum = altDugum->dokuAdresi->ilkHucreDugum;
    
    while(gecHucreDugum != 0)
    {
        if(gecHucreDugum->hucreAdresi->dnaUzunlugu % 2 == 0)
            gecHucreDugum->hucreAdresi->dnaUzunlugu = (gecHucreDugum->hucreAdresi->dnaUzunlugu / 2);
        hucreSayac++;
        gecHucreDugum = gecHucreDugum->sonraki;
    }
    
    int *sirasiz = new int[hucreSayac];
    HucreDugum *gec2HucreDugum = altDugum->dokuAdresi->ilkHucreDugum;
    int i = 0;

    while(gec2HucreDugum != 0)
    {
        sirasiz[i] = gec2HucreDugum->hucreAdresi->dnaUzunlugu;
        i++;
        gec2HucreDugum = gec2HucreDugum->sonraki;
    }
    delete altDugum->dokuAdresi;
    altDugum->dokuAdresi = new Doku();

    int *sirali = new int[hucreSayac];
    Radix *radix = new Radix(sirasiz,hucreSayac);
    sirali = radix->Sort();

    for(int j = 0; j < hucreSayac; j++)
    {
        Hucre *yeniHucre = new Hucre(sirali[j]);
        altDugum->dokuAdresi->hucreEkle(yeniHucre);
    }
}

bool IkiliAramaAgaci::mutasyon()
{
    if(kok->dokuAdresi->dokuDegeri() % 50 == 0)
    {
        mutasyonIslemleri(kok);
        return true;
    }
}

void IkiliAramaAgaci::postorderOkuVeAktar(DokuDugum *altDugum, Doku **mutasyonluDokuDizisi, int *i)
{
	if(altDugum != 0)
    {
		postorderOkuVeAktar(altDugum->sol, mutasyonluDokuDizisi, i);
		postorderOkuVeAktar(altDugum->sag, mutasyonluDokuDizisi, i);
        mutasyonluDokuDizisi[*i] = altDugum->dokuAdresi;
        (*i)++;
	}
}