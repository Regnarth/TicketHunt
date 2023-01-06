#ifndef BRISANJE_DOGADJAJA_H
#define BRISANJE_DOGADJAJA_H
// BRISANJE_DOGADJAJA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "KreiranjeDogadjaja.h"

typedef struct listaDogadjaja {
	DOGADJAJ dogadjaj;
	struct listaDogadjaja* next;
} ListaDogadjaja;

void dodajUListu(ListaDogadjaja**, DOGADJAJ*);
//int provjeraUlaznica(char*);
//int ponistiUlaznice(char*);
int brisiDogadjaj(char*);
void invertujListu(ListaDogadjaja**);
int upisiDogadjaje(ListaDogadjaja*);

#endif