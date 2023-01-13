#ifndef KREIRANJE_DOGADJAJA_H
#define KREIRANJE_DOGADJAJA_H
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Datum
{
    int dan;
    int mjesec;
    int godina;
};

struct Vrijeme_odrzavanja
{
    int sat;
    int minut;
};
typedef struct dogadjaj {
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
} DOGADJAJ;

int unosDogadjaja();
int provjeraID(char* ID);
int validacijaVremena(int sat, int minut);
int validacijaCijene(int cijena);
int validacijaBrojaMjesta(int broj_mjesta);
int validacijaKupovine(int kupuje_na_ime);
int validacijaDatuma(int dan, int mjesec, int godina);


#endif
