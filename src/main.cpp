/** 
* @file main.cpp
* @description Programın başlangıç noktası.
* @course 1.Öğretim A Grubu
* @assignment 2.Ödev
* @date 25.12.2022
* @author enes.kaya11@ogr.sakarya.edu.tr
*/

#include <sstream>
#include <fstream>
#include <iomanip>

#include "Organizma.hpp"
#include "Radix.hpp"
#include "Kontrol.hpp"
using namespace std;

int main()
{
  string satir;
  string satirYedek;
  char ch;
  ifstream dosya ("Veri.txt");
  Organizma *organizma = new Organizma();
  Sistem *sistem = new Sistem();
  Organ *organ = new Organ();
  int organSayisi = 1;
  int dokuSayisi = 0;
  int hucreSayisi;
  int* sirali;
  int sayac = 0;
  bool mutasyonlanabilir = true;
  
  /************************** VERI OKUMA ISLEMLERI **************************/
  while (getline(dosya,satir))
  {
    hucreSayisi = 0;
    satirYedek = satir;
    stringstream s(satirYedek);
    int siradaki;

    while(s>>siradaki) // Dokudaki Hücre adetini bulur.
    {
        hucreSayisi++;
    }

    stringstream ss(satir);
    siradaki = 0;
    int *sirasiz = new int[hucreSayisi];
    
    for(int i = 0; ss>>siradaki; i++) // Hücrelerin dna uzunluklarını bir diziye atar.
    {
      sirasiz[i] = siradaki;
    }
    Radix *radix = new Radix(sirasiz,hucreSayisi);
    sirali = radix->Sort(); // Radix sıralama işlemi.

    Doku *doku = new Doku();
    dokuSayisi++;

    for(int j = 0; j < hucreSayisi; j++)
    {
      Hucre *hucre = new Hucre(sirali[j]);
      doku->hucreEkle(hucre); // Dna uzunluklarını alarak hücre nesnesi oluşturur ve doku nesnesine ekler.
    }
    organ->ekle(doku);
    delete radix;
    delete[] sirasiz;

    if(dokuSayisi % 20 == 0)
    {
      sistem->ekle(organ);      
      organ = new Organ();
      organSayisi++;
      sayac = 0;
    }
    

    if(organSayisi % 100 == 0 && sayac == 0)
    {
      organizma->sistemEkle(sistem);
      sistem = new Sistem();
      sayac++;
    }
  }

  /************************** EKRANA YAZDIRMA ISLEMLERI **************************/
  while(true)
  {
    system("CLS");
    if(mutasyonlanabilir) cout << setw(20)<< " " << "ORGANIZMA" << endl;
    else cout << setw(20) << " " << "ORGANIZMA (MUTASYONA UGRADI)" << endl;

    Kontrol *kontrol = new Kontrol();
  
    SistemDugum *gecSistemDugum = organizma->ilkSistemDugum;
    while(gecSistemDugum != 0)
    {
      OrganDugum *gecOrganDugum = gecSistemDugum->sistemAdresi->ilkOrganDugum;
      while(gecOrganDugum != 0)
      {
        if(kontrol->dengeliMi(gecOrganDugum->organAdresi->bst)) cout << " ";
        else  cout << "#";
        gecOrganDugum = gecOrganDugum->sonraki;
      }
      cout << endl;
      gecSistemDugum = gecSistemDugum->sonraki;
    }

  /************************** MUTASYON ISLEMLERI **************************/
    gecSistemDugum = organizma->ilkSistemDugum;

    if (cin.get() == '\n' && mutasyonlanabilir)
    {
      while(gecSistemDugum != 0)
      {
        OrganDugum *gecOrganDugum = gecSistemDugum->sistemAdresi->ilkOrganDugum;
        while(gecOrganDugum != 0)
        {
          if(gecOrganDugum->organAdresi->bst->mutasyon()) 
          {
            int *i;
            *i = 0;
            Doku **mutasyonluDokuDizisi = new Doku*[gecOrganDugum->organAdresi->bst->dokuSayac];
            gecOrganDugum->organAdresi->bst->postorderOkuVeAktar(gecOrganDugum->organAdresi->bst->kok, mutasyonluDokuDizisi, i); //burda int alıp tekrar oluştur dene.
            gecOrganDugum->organAdresi->bst->sifirla();
            for(int j = 0; j < (*i); j++)
              gecOrganDugum->organAdresi->bst->ekle(mutasyonluDokuDizisi[j]);
            delete mutasyonluDokuDizisi;
          }
          gecOrganDugum = gecOrganDugum->sonraki;
        }
        gecSistemDugum = gecSistemDugum->sonraki;
      }
    mutasyonlanabilir = false;
    }
  }

  dosya.close();

}