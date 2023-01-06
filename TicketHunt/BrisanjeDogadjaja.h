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


#endif
