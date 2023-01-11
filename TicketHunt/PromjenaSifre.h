#ifndef PROMJENA_SIFRE_H
#define PROMJENA_SIFRE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 20
typedef struct korisnik{
	char korisnickoIme[MAX],sifra[MAX],ime[MAX],prezime[MAX];
} KORISNIK;
int promjenaSifre(char* file);
void mijenjajSifru();


#endif // PROMJENA_SIFRE_H
