#ifndef IkiliAramaAgaci_hpp
#define IkiliAramaAgaci_hpp

#include "DokuDugum.hpp"
#include "Radix.hpp"

class IkiliAramaAgaci
{
    public:	
		void araVeEkle(DokuDugum *&altDugum, Doku *doku);
		void mutasyonIslemleri(DokuDugum *altDugum);
		void sifirlaIslemleri(DokuDugum *altDugum);
	public:
		int dokuSayac;
		DokuDugum *kok;
		IkiliAramaAgaci();
		~IkiliAramaAgaci();
		bool bosMu()const;
		void ekle(Doku *doku);
		void sifirla();
		int yukseklik(DokuDugum *altDugum);
		bool mutasyon();
		void postorderOkuVeAktar(DokuDugum *altDugum, Doku **mutasyonluDokuDizisi, int *i);
};

#endif