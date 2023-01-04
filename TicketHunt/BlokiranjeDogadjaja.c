#include "BlokiranjeDogadjaja.h"

void blokirajDogadjaj()
{
    char imeDogadjaja[MAX_EVENT_NAME_LENGHT];
    printf("Unesite ime dogadjaja koji zelite da blokirate:\n");
    gets(imeDogadjaja);
    FILE* fp;
    while (provjeraAktivnostiDogadjaja(fp, imeDogadjaja) == 1)
    {
        printf("Dogadjaj je vec blokiran.\n");
        printf("Izaberite drugi događaj:\n");
        gets(imeDogadjaja);
    }

    if (memorisiDogadjaj(fp, imeDogadjaja))
    {
        printf("Dogadjaj je uspjesno blokiran.\n");
    }
}

int provjeraAktivnostiDogadjaja(FILE* fp, char* imeDogadjaja)
{
    if (fp = fopen("Blokirani.txt", "r"))
    {
        char temp[MAX_EVENT_NAME_LENGHT];
        while (fgets(temp, 50, fp))
        {
            if (strcmp(imeDogadjaja, temp) == 0)
            {
                fclose(fp);
                return 1;
            }
        }
        fclose(fp);
    }
    else
    {
        printf("Neuspjesno otvaranje datoteke.\n");
        return 0;
    }
    return 0;
}

int memorisiDogadjaj(FILE* fp, char* imeDogadjaja)
{
    if (fp = fopen("Blokirani.txt", "a"))
    {
        fprintf(fp, "%s\n", imeDogadjaja);
        fclose(fp);
        return 1;
    }
    else
    {
        printf("Neuspjesno otvaranje datoteke za dodavanje\n");
        return 0;
    }
}
