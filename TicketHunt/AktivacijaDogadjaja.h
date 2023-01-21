#pragma once
#pragma once
#ifndef AKTIVACIJA_DOGADJAJA_H
#define AKTIVACIJA_DOGADJAJA_H

#define MAX_ID_LENGHT 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct event {
	char IDDogadjaja[MAX_ID_LENGHT];
	struct event* next;
} EVENT;

void aktivirajDogadjaj();
static void dodaj(EVENT** event, char* IDDogadjaja);
int ukloniDogadjaj(FILE* fp, EVENT* event);
static void brisi(EVENT** event);

#endif