#pragma once
#ifndef AKTIVACIJA_NALOGA_H
#define AKTIVACIJA_NALOGA_H
//AKTIVACIJA_NALOGA_H
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nalog {
	char korisnickoIme[MAX];
	struct nalog* next;
} NALOG;

void aktivirajNalog();
void dodaj(NALOG** nalog, char* korisnickoIme);
int ukloniNalog(FILE* f, NALOG* nalog);
void brisi(NALOG** nalog);
void invertuj(NALOG** glava);

#endif