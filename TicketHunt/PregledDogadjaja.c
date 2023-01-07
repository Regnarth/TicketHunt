#include "PregledDogadjaja.h"
#include "KreiranjeDogadjaja.h"

void PregledDogadjaja()
{
    FILE* fp;
    if (fp = fopen("Dogadjaji.txt", "r"))
    {
        DOGADJAJ temp;
        printf("DOGADJAJI:\n");
        while (  fscanf(fp, "%s %d.%d.%d %d:%d %s %d %d %d %d %s\n", temp.naziv, &temp.datum.dan,
                 &temp.datum.mjesec, &temp.datum.godina, &temp.vrijeme.sat, &temp.vrijeme.minut, temp.mjesto,
                 &temp.cijena_ulaznice, &temp.broj_mjesta, &temp.broj_prodatih_ulaznica, &temp.kupuje_na_ime, temp.ID)   !=  EOF )

            printf("%s %d.%d.%d %d:%d %s %d %d %d %d %s\n", temp.naziv, temp.datum.dan,
                temp.datum.mjesec, temp.datum.godina, temp.vrijeme.sat, temp.vrijeme.minut, temp.mjesto,
                temp.cijena_ulaznice, temp.broj_mjesta, temp.broj_prodatih_ulaznica, temp.kupuje_na_ime, temp.ID);

        fclose(fp);
    }
    else
    {
        printf("Neuspjesno otvaranje datoteke za citanje.");
    }
}