#ifndef AKTIVACIJA_NALOGA_H
#define AKTIVACIJA_NALOGA_H
//AKTIVACIJA_NALOGA_H
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nalog{
	char korisnickoIme[MAX];
	struct nalog* next;
} NALOG;
#endif
