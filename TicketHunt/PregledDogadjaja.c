#include "PregledDogadjaja.h"
#include "KreiranjeDogadjaja.h"

void PregledDogadjaja()
{
    FILE *fp, *dat;
    
    if (fp = fopen("Dogadjaji.txt", "r"))
    {
        DOGADJAJ temp;
        printf("DOGADJAJI:\n");
        while (  fscanf(fp, "%s %d.%d.%d %d:%d %s %d %d %d %d %s\n", temp.naziv, &temp.datum.dan,
                 &temp.datum.mjesec, &temp.datum.godina, &temp.vrijeme.sat, &temp.vrijeme.minut, temp.mjesto,
                 &temp.cijena_ulaznice, &temp.broj_mjesta, &temp.broj_prodatih_ulaznica, &temp.kupuje_na_ime, temp.ID)   !=  EOF )
            {
                printf("%s %d.%d.%d %d:%d %s %d %d %d %d %s\n", temp.naziv, temp.datum.dan,
                    temp.datum.mjesec, temp.datum.godina, temp.vrijeme.sat, temp.vrijeme.minut, temp.mjesto,
                    temp.cijena_ulaznice, temp.broj_mjesta, temp.broj_prodatih_ulaznica, temp.kupuje_na_ime, temp.ID);
                    
                    char pomocno_ime[MAX];
                    char ekstenzija[6]=".txt";
                    strcpy(pomocno_ime, temp.naziv);
                    strcat(pomocno_ime,ekstenzija);
                    char red[200];

                if (dat=fopen(pomocno_ime,"r") != NULL)
                {
                    printf("Opis dogadjaja:\n");
                    while ( fgets(red,200,dat) != NULL)
                    {
                        printf("%s",red);
                    }
                    fclose(dat);
                }
                printf("\n");
            }
        fclose(fp);
    }
    else
    {
        printf("Neuspjesno otvaranje datoteke za citanje.");
    }
}