#ifndef PRIJAVA_NA_SISTEM_H
#define PRIJAVA_NA_SISTEM_H
#define N 15
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Registracija.h"
#include "PrijavaPrvogAdministratora.h"
typedef struct prijavljen {
	char korisnickoIme[MAX], sifra[MAX];
	int brPrijava, odjavljen;
} PRIJAVLJEN;
int prebrojiPrijavljeneNaloge();
int provjeraIkadPrijavljen(char* korIme);
int provjeraIspravnostiSifre(char* file, char* korIme, char* sifra);
int provjeraPonistavanjaSifre(char* korIme);
int ocitajBrojPrijava(char* korIme);
int nulirajBrojPrijava(char* korIme);
int azurirajBrojPrijava(char* korIme);
int azurirajStatus(char* korIme);
int prijava(char* file, USER* user);
int prijavaNaSistem(USER* user);
#endif // PRIJAVA_NA_SISTEM_H
