#pragma once
#pragma once
#ifndef KUPOVINA_ULAZNICE_H
#define kUPOVINA_ULAZNICE_H
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "KreiranjeDogadjaja.h"
#include "Registracija.h"

void KupovinaUlaznice(USER* korisnik);
void ispisDogadjaja(DOGADJAJ* pom);
void memorisanjeUlaznice(DOGADJAJ* pom, USER* korisnik, char* ime);
void unosPodataka(DOGADJAJ* dogadjaj);
int validacijaNaziva(char* naziv);



#endif