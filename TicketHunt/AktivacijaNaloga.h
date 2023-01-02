#pragma once
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nalog{
	char korisnickoIme[MAX];
	struct nalog* next;
} NALOG;

void aktivirajNalog();
void dodaj(NALOG**, char*);
int ukloniNalog(FILE*, NALOG*);
void brisi(NALOG**);