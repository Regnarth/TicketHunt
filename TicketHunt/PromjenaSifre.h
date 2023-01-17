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
static int provjeraPostojanjaBroja(char* sifra);
static int provjeraPostojanjaVelikogSlova(char* sifra);
static int provjera(char* sifra, char* novaSifra);
int birajVrstuNaloga();
int prebrojiNaloge(char *file);
int provjeraPostojanjaKorImena(char *file,char *korIme);
int promjenaSifre(char *file);
void mijenjajSifru();
static int provjeraDuzineSifre(char* sifra);
void mijenjajSifru(USER *user);


#endif // PROMJENA_SIFRE_H
