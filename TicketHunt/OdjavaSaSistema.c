#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Prijava.h"
#include "Prijava.c"
void odjavaSaSistema(PRIJAVLJEN* prijavljen)
{
    char* linija_za_izmjenu;
    FILE* f;
    int broj_linije=0;
    int odgovor=0;
    int odgovor_validan = 0;
    while (odgovor_validan == 0)
    {
        printf("Da li ste sigurni da zelite da se odjavite? 'Da-1' ili 'Ne-0' :"); scanf("%d", &odgovor);
        if (validacijaOdjave(odgovor) == 1)
        {
            odgovor_validan = 1;
        }
    }
    if(f=fopen("Prijavljeni korisnici.txt", "r"))
    {
        int lineLength = 255;
        char line[lineLength];
        int ukupan_br_linija=0;
        while(fgets(line, lineLength, f))
    {
        ukupan_br_linija++;
        char* pch;
        pch = strtok (line," ");
        char* username = pch;
        if(strcmp(username,prijavljen->korisnickoIme)==0)
        {
            broj_linije=ukupan_br_linija;
        }
    }
    fclose(f);
    izmjenaLinije(broj_linije);
    }
}

void izmjenaLinije(int broj_linije)
{
    FILE* f;
    char* linija_za_izmjenu="";
    if(f=fopen("Prijavljeni korisnici.txt", "r"))
    {
        int lineLength = 255;
        char line[lineLength];
        int ukupan_br_linija=0;
        while(fgets(line, lineLength, f))
        {
            ukupan_br_linija++;
            if(ukupan_br_linija==broj_linije)
            {
                linija_za_izmjenu=line;

                char* pch;
                pch = strtok (line," ");
                char* username = pch;

                pch = strtok (NULL," ");
                char* sifra = pch;

                pch = strtok (NULL," ");
                char* broj_prijava = pch;

                pch = strtok (NULL," ");
                char* odjava = pch;
                odjava="1";
                char nova_linija[255]="";
                strcat(nova_linija,username);
                strcat(nova_linija," ");
                strcat(nova_linija, sifra);
                strcat(nova_linija, " ");
                strcat(nova_linija, broj_prijava);
                strcat(nova_linija, " ");
                strcat(nova_linija, odjava);
                strcat(nova_linija, " ");
                strcat(nova_linija, "\n");
                fclose(f);
                izmjena(broj_linije,nova_linija);
                printf("Uspjesno ste se odjavili! ");
            }
        }
    }
}

void izmjena(int broj_linije, char* nova_linija)
{
    int br;
    char line[1000];
    FILE* f1;
    FILE* f2;
    if(f1 = fopen("Prijavljeni korisnici.txt", "r"))
       {
       if(f2 = fopen("replace.tmp", "w"))
    {
    br = 0;
    while ((fgets(line, 1000, f1)) != NULL)
    {
        br++;
        if (br == broj_linije)
            fputs(nova_linija, f2);
        else
            fputs(line, f2);
    }
    fclose(f1);
    fclose(f2);
    remove("Prijavljeni korisnici.txt");
    rename("replace.tmp", "Prijavljeni korisnici.txt");
    return 0;
    }
    }
}
int validacijaOdjave(int odgovor)
{
    if (odgovor == 1 || odgovor == 0)
        return 1;
    else
        return 0;
}


