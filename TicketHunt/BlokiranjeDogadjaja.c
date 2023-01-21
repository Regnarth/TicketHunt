
#include "BlokiranjeDogadjaja.h"
#include "LoadConfig.h"

void blokirajDogadjaj()
{
    char IDDogadjaja[MAX_ID_LENGHT] = "";
    printf("Unesite ID dogadjaja koji zelite da blokirate:\n");
    scanf("%s", IDDogadjaja);
    //gets(IDDogadjaja);
    FILE* fp = 0;
    while (provjeraAktivnostiDogadjaja(fp, IDDogadjaja) == 1)
    {
        printf("Dogadjaj je vec blokiran.\n");
        printf("Izaberite drugi dogadjaj:\n");
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
    if (fp = fopen(concat(CONFIG_DEV_FOLDER, "Blokirani.txt"), "r"))
    {
        char temp[MAX_ID_LENGHT] = "";
        while (fscanf(fp,"%s", temp)!=EOF)
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
        return 0;
    }
    return 0;
}

int memorisiDogadjaj(FILE* fp, char* IDDogadjaja)
{
    if (fp = fopen(concat(CONFIG_DEV_FOLDER, "Blokirani.txt"), "a"))
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