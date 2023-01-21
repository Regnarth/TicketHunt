#ifndef ODJAVA_SA_SISTEMA_H
#define ODJAVA_SA_SISTEMA_H
#define MAX 20
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "PrijavaNaSistem.h"

void odjavaSaSistema(char* prijavljen);
void izmjenaLinije(int broj_linije);
void izmjena(int broj_linije, char* nova_linija);
int validacijaOdjave(int odgovor);

#endif
