#pragma once
#pragma once
#ifndef BLOKIRANJE_DOGADJAJA_H
#define BLOKIRANJE_DOGADJAJA_H

#define MAX_ID_LENGHT 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void blokirajDogadjaj();
int provjeraAktivnostiDogadjaja(FILE* fp, char* IDDogadjaja);
int memorisiDogadjaj(FILE* fp, char* IDDogadjaja);

#endif