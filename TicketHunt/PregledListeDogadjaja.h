#ifndef PREGLED_LISTE_DOGADJAJA_H
#define PREGLED_LISTE_DOGADJAJA_H
#include"KreiranjeDogadjaja.h"
typedef struct cvor{
	char naziv[MAX];
	struct Datum datum;
	char mjesto[MAX];
	char ID[MAX];
	struct Vrijeme_odrzavanja vrijeme;
	int cijena_ulaznice;
	int broj_mjesta;
	int broj_prodatih_ulaznica;
	int kupuje_na_ime;
	char opis_dogadjaja[MAX];
	struct cvor *sljedeci;
} CVOR;
void pregledListeDogadjaja(char *file);
void dodaj(CVOR** dogadjaj, char* naziv);
CVOR* trazi(CVOR *dogadjaj, char *naziv);
void pisi(CVOR *dogadjaj);
void brisi_listu(CVOR **dogadjaj);
void pregledListeDogadjaja(char *file);

#endif // PREGLED_LISTE_DOGADJAJA_H
