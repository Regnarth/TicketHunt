#include "PregledDogadjaja.h"
#include "KreiranjeDogadjaja.h"
#include "LoadConfig.h"
void PregledDogadjaja()
{
    FILE* fp = 0, * dat = 0;

    if (fp = fopen(concat(CONFIG_DEV_FOLDER, "Dogadjaji.txt"), "r"))
    {
        DOGADJAJ temp;
        printf("DOGADJAJI:\n");
        while (fscanf(fp, "%s %d.%d.%d %d:%d %s %d %d %d %d %s\n", temp.naziv, &temp.datum.dan,
            &temp.datum.mjesec, &temp.datum.godina, &temp.vrijeme.sat, &temp.vrijeme.minut, temp.mjesto,
            &temp.cijena_ulaznice, &temp.broj_mjesta, &temp.broj_prodatih_ulaznica, &temp.kupuje_na_ime, temp.ID) != EOF)
        {
            printf("Naziv dogadjaja:%s\n Vrijeme odrzavanja: %d.%d.%d %d:%d\n Mjesto: %s\n Cijena ulaznice:%d\n Broj mjesta: %d\n Broj prodatih ulaznica: %d\n Kupuje na ime: %d\n  ID:%s\n", temp.naziv, temp.datum.dan,
                temp.datum.mjesec, temp.datum.godina, temp.vrijeme.sat, temp.vrijeme.minut, temp.mjesto,
                temp.cijena_ulaznice, temp.broj_mjesta, temp.broj_prodatih_ulaznica, temp.kupuje_na_ime, temp.ID);

            char pomocno_ime[MAX] ="";
            char ekstenzija[6] = ".txt";
            strcpy(pomocno_ime, temp.naziv);
            strcat(pomocno_ime, ekstenzija);
            char red[505] = "";

            //if (dat = fopen(concat(CONFIG_DATA_FOLDER, pomocno_ime), "r")) //
            //if (dat=fopen(pomocno_ime,"r"))
            //{
            //    printf("Opis dogadjaja:\n");
            //    while (fgets(red, 500, dat)>0)
            //    {
            //        printf("%s", red);
            //    }
            //    fclose(dat);
            //}
            //printf("\n");
     
        }
        fclose(fp);
    }
    else
    {
        printf("Neuspjesno otvaranje datoteke za citanje.");
    }
}