#ifndef KREIRANJE_NALOGA_H
#define KREIRANJE_NALOGA_H
//KREIRANJE_NALOGA_H
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct klijent {
	char ime[MAX];
	char prezime[MAX];
	char korisnickoIme[MAX];
	char sifra[MAX];
	int brojPrijava;
} KLIJENT;

typedef struct administrator {
	char ime[MAX];
	char prezime[MAX];
	char korisnickoIme[MAX];
	char sifra[MAX];
	int brojPrijava;
} ADMINISTRATOR;
#endif

