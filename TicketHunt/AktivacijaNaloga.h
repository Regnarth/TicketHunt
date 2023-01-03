#ifndef AKTIVACIJANALOGA_H
#define AKTIVACIJANALOGA_H
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nalog{
	char korisnickoIme[MAX];
	struct nalog* next;
} NALOG;
#endif
