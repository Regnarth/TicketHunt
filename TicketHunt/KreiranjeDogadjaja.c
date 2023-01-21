#include "KreiranjeDogadjaja.h"
#include "LoadConfig.h"
int unosDogadjaja() {
    DOGADJAJ dogadjaj;
    FILE* f;

    printf("Unesite naziv dogadjaja:"); scanf("%s", dogadjaj.naziv);
    printf("Unesite mjesto odrzavanja: ");
    getchar();
    gets(dogadjaj.mjesto);
    //scanf("%s", dogadjaj.mjesto);

    printf("Unesite opis dogadjaja:");
    //getchar();
    gets(dogadjaj.opis_dogadjaja);
    char naziv_datoteke[150];
    sprintf(naziv_datoteke, "%s.txt", dogadjaj.naziv);

    if (f = fopen(concat(CONFIG_DATA_FOLDER,naziv_datoteke), "w"))
    {
        fprintf(f, "%s", dogadjaj.opis_dogadjaja);
        fclose(f);
    }


    int datum_validan = 0;
    while (datum_validan == 0)
    {
        printf("Datum dogadjaja(dd mm yyyy):"); scanf("%d %d %d", &dogadjaj.datum.dan, &dogadjaj.datum.mjesec, &dogadjaj.datum.godina);

        if (validacijaDatuma(dogadjaj.datum.dan, dogadjaj.datum.mjesec, dogadjaj.datum.godina) == 1)
        {
            datum_validan = 1;
        }

    }
    int vrijeme_validno = 0;
    while (vrijeme_validno == 0)
    {
        printf("Unesite vrijeme dogadjaja(hh mm):"); scanf("%d %d", &dogadjaj.vrijeme.sat, &dogadjaj.vrijeme.minut);

        if (validacijaVremena(dogadjaj.vrijeme.sat, dogadjaj.vrijeme.minut) == 1)
        {
            vrijeme_validno = 1;
        }

    }
    int cijena_validna = 0;
    while (cijena_validna == 0)
    {
        printf("Cijena ulaznice:"); scanf("%d", &dogadjaj.cijena_ulaznice);
        if (validacijaCijene(dogadjaj.cijena_ulaznice) == 1)
        {
            cijena_validna = 1;
        }

    }

    int broj_mjesta_validan = 0;
    while (broj_mjesta_validan == 0)
    {
        printf("Broj mjesta:"); scanf("%d", &dogadjaj.broj_mjesta);
        if (validacijaBrojaMjesta(dogadjaj.broj_mjesta) == 1)
        {
            broj_mjesta_validan = 1;
        }

    }
    dogadjaj.broj_prodatih_ulaznica = 0;
    int kupuje_validno = 0;
    while (kupuje_validno == 0)
    {

        printf("Da li kupujete na ime? 'Da-1' ili 'Ne-0' :"); scanf("%d", &dogadjaj.kupuje_na_ime);
        if (validacijaKupovine(dogadjaj.kupuje_na_ime) == 1)
        {
            kupuje_validno = 1;
        }


    }
    if (f = fopen(concat(CONFIG_DEV_FOLDER,"Dogadjaji.txt"), "a+"))
    {
        DOGADJAJ temp;
        int provjera_postojanja = 0;
        while (fscanf(f, "%s %d.%d.%d %d:%d %s %d %d %d %d %s\n", temp.naziv, &temp.datum.dan, &temp.datum.mjesec,
            &temp.datum.godina, &temp.vrijeme.sat, &temp.vrijeme.minut, temp.mjesto, &temp.cijena_ulaznice,
            &temp.broj_mjesta, &temp.broj_prodatih_ulaznica, &temp.kupuje_na_ime, temp.ID) != EOF)
        {
            if ((strcmp(temp.naziv, dogadjaj.naziv) == 0) && (strcmp(temp.mjesto, dogadjaj.mjesto) == 0) &&
                (temp.datum.godina == dogadjaj.datum.godina) && (temp.datum.mjesec == dogadjaj.datum.mjesec) &&
                (temp.datum.dan == dogadjaj.datum.dan) && (temp.vrijeme.sat == dogadjaj.vrijeme.sat) && (temp.vrijeme.minut == dogadjaj.vrijeme.minut))
            {

                provjera_postojanja++;
            }

        }
        if (provjera_postojanja == 0)
        {
            printf("Unesite ID dogadjaja: ");
            scanf("%s", dogadjaj.ID);
            while (provjeraID(dogadjaj.ID))
            {
                printf("ID vec postoji, unesite novi ID:"); scanf("%s", dogadjaj.ID);
            }
            fprintf(f, "%s %d.%d.%d %d:%d %s %d %d %d %d %s\n", dogadjaj.naziv, dogadjaj.datum.dan,
                dogadjaj.datum.mjesec, dogadjaj.datum.godina, dogadjaj.vrijeme.sat, dogadjaj.vrijeme.minut,
                dogadjaj.mjesto, dogadjaj.cijena_ulaznice, dogadjaj.broj_mjesta, dogadjaj.broj_prodatih_ulaznica, dogadjaj.kupuje_na_ime, dogadjaj.ID);
        }
        else {
            printf("---Dogadjaj koji ste unijeli vec postoji!---");
            return 0;
        }

        fclose(f);
    }

    else {
        printf("Neuspjesno otvaranje datoteke.");
        return 0;
    }
    printf("Dogadjaj uspjesno dodat!\n  ");
    return 1;
}

int provjeraID(char* ID) {
    FILE* f = 0;
    DOGADJAJ temp;
    if (f = fopen(concat(CONFIG_DEV_FOLDER,"Dogadjaji.txt"), "r")) {
        while (fscanf(f, "%s %d.%d.%d %d:%d %s %d %d %d %d %s\n", temp.naziv, &temp.datum.dan, &temp.datum.mjesec,
            &temp.datum.godina, &temp.vrijeme.sat, &temp.vrijeme.minut, temp.mjesto, &temp.cijena_ulaznice,
            &temp.broj_mjesta, &temp.broj_prodatih_ulaznica, &temp.kupuje_na_ime, temp.ID) != EOF)
        {
            if (strcmp(temp.ID, ID) == 0)
            {
                fclose(f);
                return 1;
            }
        }
        fclose(f);
    }
    return 0;
}

int validacijaVremena(int sat, int minut)
{
    int vrijeme_validno = 1;
    if (sat < 0 || sat>23)
    {
        vrijeme_validno = 0;
    }
    if (minut < 0 || minut>59)
    {
        vrijeme_validno = 0;
    }
    if (vrijeme_validno == 0)
    {
        printf("Vrijeme nije validno!\n");
        return 0;
    }
    return 1;
}
int validacijaCijene(int cijena)
{
    if (cijena < 0)
    {
        printf("Cijena nije validna!\n");
        return 0;
    }
    return 1;
}
int validacijaBrojaMjesta(int broj_mjesta)
{
    if (broj_mjesta <= 0)
    {
        printf("Broj mjesta nije validan!\n");
        return 0;
    }
    return 1;
}
int validacijaKupovine(int kupuje_na_ime)
{
    if (kupuje_na_ime == 1 || kupuje_na_ime == 0)
        return 1;
    else
        return 0;
}
int validacijaDatuma(int dan, int mjesec, int godina)
{
    if (godina < 2023)
    {
        printf("Godina nije validna!\n");
        return 0;
    }
    if (dan < 1)
    {
        printf("Dan nije validan!\n");
        return 0;
    }
    if (mjesec < 1 || mjesec>12)
    {
        printf("Mjesec nije validan!\n");
        return 0;
    }
    if (mjesec == 2)
    {
        int godina_prestupna = 0;
        if (godina % 400 == 0)
            godina_prestupna = 1;
        if (godina % 4 == 0 && godina % 100 != 0)
            godina_prestupna = 1;
        if (godina_prestupna == 1)
        {
            if (dan > 29)
            {
                printf("Dan nije validan!\n");
                return 0;
            }
        }
        else {
            if (dan > 28)
            {
                printf("Dan nije validan!\n");
                return 0;
            }
        }
    }
    else if (mjesec == 4 || mjesec == 6 || mjesec == 9 || mjesec == 11)
    {
        if (dan > 30)
        {
            printf("Dan nije validan!\n");
            return 0;
        }
    }
    else
    {
        if (dan > 31)
        {
            printf("Dan nije validan!\n");
            return 0;
        }
    }
    return 1;
}