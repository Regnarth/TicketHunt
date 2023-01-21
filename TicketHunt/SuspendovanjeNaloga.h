#ifndef SUSPENDOVANJE_NALOGA_H
#define SUSPENDOVANJE_NALOGA_H
//SUSPENDOVANJE_NALOGA_H
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void suspendujNalog();
int provjeraSuspenzije(FILE* f, char* korisnickoIme);
int memorisiNalog(FILE* f, char* korisnickoIme); 
int provjeriUsernameKorisnika(char* username);
   

#endif
