#include "BlokiranjeDogadjaja.h"

void blokirajDogadjaj()
{
    char IDDogadjaja[MAX_ID_LENGHT];
    printf("Unesite ID dogadjaja koji zelite da blokirate:\n");
    scanf("%s", IDDogadjaja);
    //gets(IDDogadjaja);
    FILE* fp;
    while (provjeraAktivnostiDogadjaja(fp, IDDogadjaja) == 1)
    {
        printf("Dogadjaj je vec blokiran.\n");
        printf("Izaberite drugi događaj:\n");
        scanf("%s", IDDogadjaja);
        //gets(IDDogadjaja);
    }

    if (memorisiDogadjaj(fp, IDDogadjaja))
    {
        printf("Dogadjaj je uspjesno blokiran.\n");
    }
}

int provjeraAktivnostiDogadjaja(FILE* fp, char* IDDogadjaja)
{
    if (fp = fopen("Blokirani.txt", "r"))
    {
        char temp[MAX_ID_LENGHT];
        while (fgets(temp, MAX_ID_LENGHT, fp))
        {
            if (strcmp(IDDogadjaja, temp) == 0)
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

int memorisiDogadjaj(FILE* fp, char* IDDogadjaja)
{
    if (fp = fopen("Blokirani.txt", "a"))
    {
        fprintf(fp, "%s\n", IDDogadjaja);
        fclose(fp);
        return 1;
    }
    else
    {
        printf("Neuspjesno otvaranje datoteke za dodavanje\n");
        return 0;
    }
}