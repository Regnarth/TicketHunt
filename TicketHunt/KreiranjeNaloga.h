#pragma once
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct klijent {
	char ime[MAX];
	char prezime[MAX];
	char korisnickoIme[MAX];
	char sifra[MAX];
	int suspendovan;
} KLIJENT;

typedef struct administrator {
	char ime[MAX];
	char prezime[MAX];
	char korisnickoIme[MAX];
	char sifra[MAX];
} ADMINISTRATOR;

void kreirajNalog();
int dodajKlijenta(FILE*, KLIJENT*);
int dodajAdministratora(FILE*, ADMINISTRATOR*);
int traziKlijenta(FILE*, char*);
int traziAdministratora(FILE*, char*);
int provjeraFormataSifre(char*);
void unosKlijenta(KLIJENT*);
void unosAdministratora(ADMINISTRATOR*);

