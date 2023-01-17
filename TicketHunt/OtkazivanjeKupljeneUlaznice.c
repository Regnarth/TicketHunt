#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "KupovinaUlaznice.c"
//#include "KupovinaUlaznice.h"

void otkazivanjeKupljeneUlaznice(char* korisnickoIme)
{
    FILE* f;
    char sifra_ulaznice[255];
    int broj_linije=0;
    int ukupan_broj_linija = 0;
    printf("Unesite sifru ulaznice koju zelite da otkazete: ");
    scanf("%s", sifra_ulaznice);
    int sifra_validna=0;
    if(f=fopen("SifraKorisnicko.txt", "r"))
    {

        int lineLength = 255;
        char line[lineLength];
        while(fgets(line, lineLength, f))
    {
        ukupan_broj_linija++;
        char* pch;
        pch = strtok (line," ");
        char* sifra = pch;
        if(strcmp(sifra,sifra_ulaznice)==0)
        {
            pch = strtok (NULL, " ");
            char* username = pch;
            if(strcmp(username, korisnickoIme)==0)
            {
                sifra_validna=1;
                broj_linije = ukupan_broj_linija;
            }
        }
    }
    fclose(f);
    if(sifra_validna==0)
    {
        printf("Niste kupili ulaznicu sa datom sifrom!");
    }
    else if (sifra_validna == 1){
        obrisiLiniju(broj_linije);
        obrisiLiniju_drugifajl(broj_linije);
         printf("Ulaznica je uspjesno otkazana.");
    }
}
else{
    printf("Greska prilikom otvaranja fajla!");
}
}

void obrisiLiniju(int broj_linije){
    int line_number=0;
    FILE* fptr1 = fopen("SifraKorisnicko.txt","r");
    FILE* fptr2 = fopen("replica.txt", "w");
    char curr = getc(fptr1);
    if(curr!=EOF) {line_number =1;}
    while(1)
    {
      if(broj_linije!= line_number)
        putc(curr, fptr2);
        curr = getc(fptr1);
        if(curr =='\n') line_number++;
        if(curr == EOF) break;
    }
    fclose(fptr1);
    fclose(fptr2);
    const char* filename="SifraKorisnicko.txt";
    const char* pomocnifajl="pomocni.txt";
    rename(filename, pomocnifajl);
    remove(filename);
    rename("replica.txt", filename);
    remove(pomocnifajl);
}

void obrisiLiniju_drugifajl(int broj_linije)
{
    int line_number=0;
    FILE* fptr1 = fopen("Ulaznice.txt","r");
    FILE* fptr2 = fopen("replica.txt", "w");
    char curr = getc(fptr1);
    if(curr!=EOF) {line_number =1;}
    while(1)
    {
      if(broj_linije!= line_number)
        putc(curr, fptr2);
        curr = getc(fptr1);
        if(curr =='\n') line_number++;
        if(curr == EOF) break;
    }
    fclose(fptr1);
    fclose(fptr2);
    const char* filename="Ulaznice.txt";
    const char* pomocnifajl="pomocni.txt";
    rename(filename, pomocnifajl);
    remove(filename);
    rename("replica.txt", filename);
    remove(pomocnifajl);
}
