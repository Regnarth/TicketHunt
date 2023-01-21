#include "PregledUlaznica.h"
#include "KreiranjeDogadjaja.h"
#include "LoadConfig.h"
void pregled_prodatih_ulaznica()
{
    FILE* fp;

    if (fp = fopen(concat(CONFIG_DEV_FOLDER,"Ulaznice.txt"), "r"))
    {
        DOGADJAJ temp;
        char ime[MAX];
        char sifra[MAX];
        printf("ULAZNICE:\n");
        while (fscanf(fp, "%s %s %s %d.%d.%d %d:%d %s %d %d %d %s\n", sifra, temp.ID, temp.naziv, &temp.datum.dan,
            &temp.datum.mjesec, &temp.datum.godina, &temp.vrijeme.sat, &temp.vrijeme.minut, temp.mjesto,
            &temp.cijena_ulaznice, &temp.broj_mjesta, &temp.broj_prodatih_ulaznica, ime) != EOF)
        {
            printf(" Sifra ulaznice: %s\n ID dogadjaja: %s\n Naziv dogadjaja: %s\n Vrijeme odrzavanja: %d.%d.%d %d:%d\n Mjesto: %s\n Cijena ulaznice:%d\n Broj mjesta: %d\n Broj prodatih ulaznica: %d\n Ime:%s\n\n",
                sifra, temp.ID, temp.naziv, temp.datum.dan, temp.datum.mjesec, temp.datum.godina, temp.vrijeme.sat, temp.vrijeme.minut, temp.mjesto,
                temp.cijena_ulaznice, temp.broj_mjesta, temp.broj_prodatih_ulaznica, ime);
        }
        fclose(fp);
    }
    else
    {
        printf("Neuspjesno otvaranje datoteke za citanje.");
    }
}