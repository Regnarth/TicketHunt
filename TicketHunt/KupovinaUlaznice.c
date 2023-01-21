#include <stdio.h>
#include <string.h>
#include "KupovinaUlaznice.h"
#include "KreiranjeDogadjaja.h"
#include "Registracija.h"
#include "LoadConfig.h"
#define MAX 20

void ispisDogadjaja(DOGADJAJ* pom)
{
    printf("%s %d %d %d %s %d:%d %d\n", pom->naziv, pom->datum.dan, pom->datum.mjesec, pom->datum.godina, pom->mjesto, pom->vrijeme.sat, pom->vrijeme.minut, pom->cijena_ulaznice);
}
void KupovinaUlaznice(USER* korisnik)
{
    DOGADJAJ pom;
    do
    {
        unosPodataka(&pom);
    } while (!provjeraPostojanjaU(&pom));
    ispisDogadjaja(&pom);
    char ime[MAX] = "Bez Imena";
    if (provjeraKupovanjaNaIme(&pom))
    {
        printf("Unesite Vase ime: ");
        scanf("%s", ime);
    }
    if (nacinPreuzimanja() == 1)printf("Preuzmite vasu ulaznicu na adresi: ul. Mihajla Seve 23\n"); else ispisDogadjaja(&pom); // preuzimanje
    // else ispisDogadjaja(&pom);
    if (provjeraRasprodanosti())
    {
        printf("Ulaznice za ovaj dogadjaj su rasprodate!\n");
    }
    else
    {

        if (korisnik->kredit >= pom.cijena_ulaznice)
        {
            korisnik->kredit -= pom.cijena_ulaznice;
            memorisanjeUlaznice(&pom, korisnik, ime);
            printf("Uspjesna kupovina: %s %s %d.%d.%d %d:%d\n", ime, pom.naziv, pom.datum.dan, pom.datum.mjesec, pom.datum.godina, pom.vrijeme.sat, pom.vrijeme.minut);
        }
        else
        {
            printf("Nedovoljno kredita na racunu!\n");
        }


    }

}

int validacijaNaziva(char* naziv)
{
    FILE* f;
    if (f = fopen(concat(CONFIG_DEV_FOLDER, "Dogadjaji.txt"), "r"))
    {
        int lineLength = 255;
        char line[255];

        while (fgets(line, lineLength, f)) {

            char delimiter[] = " ";

            char* prva_rijec = strtok(line, delimiter);
            if (strcmp(prva_rijec, naziv) == 0)
            {
                return 1;
            }

        }
    }
    return 0;
}

void unosPodataka(DOGADJAJ* dogadjaj)
{
    int naziv_validan = 0;
    while (naziv_validan == 0)
    {
        printf("Unesite naziv dogadjaja:");
        scanf("%s", dogadjaj->naziv);

        if (validacijaNaziva(dogadjaj->naziv) == 1)
        {
            naziv_validan = 1;
        }

    }

    printf("Unesite mjesto odrzavanja:");
    getchar();
    gets(dogadjaj->mjesto);

    int datum_validan = 0;
    while (datum_validan == 0)
    {
        printf("Datum dogadjaja(dd mm yyyy):");
        scanf("%d %d %d", &dogadjaj->datum.dan, &dogadjaj->datum.mjesec, &dogadjaj->datum.godina);

        if (validacijaDatuma(dogadjaj->datum.dan, dogadjaj->datum.mjesec, dogadjaj->datum.godina) == 1)
        {
            datum_validan = 1;
        }

    }
    int vrijeme_validno = 0;
    while (vrijeme_validno == 0)
    {
        printf("Unesite vrijeme dogadjaja(hh mm):");
        scanf("%d %d", &dogadjaj->vrijeme.sat, &dogadjaj->vrijeme.minut);

        if (validacijaVremena(dogadjaj->vrijeme.sat, dogadjaj->vrijeme.minut) == 1)
        {
            vrijeme_validno = 1;
        }

    }
}
int provjeraPostojanjaU(DOGADJAJ* dogadjaj)
{
    FILE* fp;
    if (fp = fopen(concat(CONFIG_DEV_FOLDER, "Dogadjaji.txt"), "r"))
    {
        DOGADJAJ temp;

        while (fscanf(fp, "%s %d.%d.%d %d:%d %s %d %d %d %d %s\n", temp.naziv, &temp.datum.dan, &temp.datum.mjesec,
            &temp.datum.godina, &temp.vrijeme.sat, &temp.vrijeme.minut, temp.mjesto, &temp.cijena_ulaznice,
            &temp.broj_mjesta, &temp.broj_prodatih_ulaznica, &temp.kupuje_na_ime, temp.ID) != EOF)
        {
            if (strcmp(dogadjaj->naziv, temp.naziv) == 0)
            {
                // printf("%s %d.%d.%d %d:%d %s %d %d %d %d\n", temp.naziv, temp.datum.dan, temp.datum.mjesec, temp.datum.godina, temp.vrijeme.sat, temp.vrijeme.minut, temp.mjesto,
                  //   temp.cijena_ulaznice, temp.broj_mjesta, temp.broj_prodatih_ulaznica, temp.kupuje_na_ime);
                dogadjaj->cijena_ulaznice = temp.cijena_ulaznice;
                dogadjaj->broj_mjesta = temp.broj_mjesta;
                dogadjaj->broj_prodatih_ulaznica = temp.broj_prodatih_ulaznica;
                dogadjaj->kupuje_na_ime = temp.kupuje_na_ime;
                strcpy(dogadjaj->ID, temp.ID);
                //printf("%d BAM ", temp.cijena_ulaznice);
                return 1;
            }
        }
        fclose(fp);
    }
    return 0;
}

int provjeraKupovanjaNaIme(DOGADJAJ* dogadjaj)
{
    FILE* fp;
    if (fp = fopen(concat(CONFIG_DEV_FOLDER, "Dogadjaji.txt"), "r"))
    {
        DOGADJAJ temp;

        while (fscanf(fp, "%s %d.%d.%d %d:%d %s %d %d %d %d %s\n", temp.naziv, &temp.datum.dan, &temp.datum.mjesec,
            &temp.datum.godina, &temp.vrijeme.sat, &temp.vrijeme.minut, temp.mjesto, &temp.cijena_ulaznice,
            &temp.broj_mjesta, &temp.broj_prodatih_ulaznica, &temp.kupuje_na_ime, temp.ID) != EOF)
        {
            if (temp.kupuje_na_ime == 1)
            {
                return 1;
            }
        }
        fclose(fp);
    }
    return 0;
}

int nacinPreuzimanja()
{
    int pom;
    do
    {
        printf("Ulaznice zelite da preuzmete: 1 (Licno) , 2 (Elektronski)");
        scanf("%d", &pom);
    } while (pom != 1 && pom != 2);
    return pom;
}
int provjeraRasprodanosti()
{
    FILE* fp;
    if (fp = fopen(concat(CONFIG_DEV_FOLDER, "Dogadjaji.txt"), "r"))
    {
        DOGADJAJ temp;

        while (fscanf(fp, "%s %d.%d.%d %d:%d %s %d %d %d %d %s\n", temp.naziv, &temp.datum.dan, &temp.datum.mjesec,
            &temp.datum.godina, &temp.vrijeme.sat, &temp.vrijeme.minut, temp.mjesto, &temp.cijena_ulaznice,
            &temp.broj_mjesta, &temp.broj_prodatih_ulaznica, &temp.kupuje_na_ime, temp.ID) != EOF)
        {
            if (temp.broj_prodatih_ulaznica == temp.broj_mjesta)
            {
                return 1;
            }
        }
        fclose(fp);
    }
    return 0;
}

void memorisanjeUlaznice(DOGADJAJ* pom, USER* korisnik, char* ime)
{
    char sifra[15];
    sprintf(sifra, "%d", SAVED_ID);
    FILE* fp;
    if (fp = fopen(concat(CONFIG_DEV_FOLDER, "Ulaznice.txt"), "a"))
    {
        if (pom->kupuje_na_ime == 1)
        {
            fprintf(fp, "%s %s %s %d.%d.%d %d:%d %s %d %d %d %s \n", sifra, pom->ID, pom->naziv, pom->datum.dan,
                pom->datum.mjesec, pom->datum.godina, pom->vrijeme.sat, pom->vrijeme.minut, pom->mjesto,
                pom->cijena_ulaznice, pom->broj_mjesta, pom->broj_prodatih_ulaznica, ime);
        }
        else fprintf(fp, "%s %s %s %d.%d.%d %d:%d %s %d %d %d %s \n", sifra, pom->ID, pom->naziv, pom->datum.dan,
            pom->datum.mjesec, pom->datum.godina, pom->vrijeme.sat, pom->vrijeme.minut, pom->mjesto,
            pom->cijena_ulaznice, pom->broj_mjesta, pom->broj_prodatih_ulaznica, "Bez Imena");
        fclose(fp);
        char pomoc[30] = "";
        strcat(pomoc, korisnik->username);
        strcat(pomoc, ".txt");
        if (fp = fopen(concat(CONFIG_DATA_FOLDER, pomoc), "a")) {
            fprintf(fp, "%s %s %s %d.%d.%d %d:%d %s %d %d %d %s \n", sifra, pom->ID, pom->naziv, pom->datum.dan,
                pom->datum.mjesec, pom->datum.godina, pom->vrijeme.sat, pom->vrijeme.minut, pom->mjesto,
                pom->cijena_ulaznice, pom->broj_mjesta, pom->broj_prodatih_ulaznica, ime);
            fclose(fp);
        }
    }
    if (fp = fopen(concat(CONFIG_DEV_FOLDER, "SifraKorisnicko.txt"), "a")) {
        if (pom->kupuje_na_ime == 1) {
            fprintf(fp, "%s %s \n", sifra, ime);

        }
        else fprintf(fp, "%s %s \n", sifra, "Bez imena");
        fclose(fp);
    }
    SAVED_ID++;
    updateSaved();
}