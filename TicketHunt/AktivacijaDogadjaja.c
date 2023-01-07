#include "AktivacijaDogadjaja.h"
#include "BlokiranjeDogadjaja.h"

void aktivirajDogadjaj()
{
    char IDDogadjaja[MAX_ID_LENGHT];
    printf("Unesite ID dogadjaja koji zelite da aktivirate:\n");
    scanf("%s", IDDogadjaja);
    //gets(IDDogadjaja);
    FILE* fp;
    while (provjeraAktivnostiDogadjaja(fp, IDDogadjaja) == 0)
    {
        printf("Dogadjaj nije blokiran.\n");
        return;
    }

    EVENT* event = 0;
    if (fp = fopen("Blokirani.txt", "r"))
    {
        char temp[MAX_ID_LENGHT];
        while (fgets(temp, MAX_ID_LENGHT, fp))
        {
            if (strcmp(temp, IDDogadjaja) != 0)
            {
                dodaj(&event, temp);
            }
        }
        fclose(fp);
    }
    if (ukloniDogadjaj(fp, event))
    {
        printf("Dogadjaj uspjesno aktiviran");
    }

    brisi(&event);

}
void dodaj(EVENT** event, char* IDDogadjaja)
{
    EVENT* novi = (EVENT*)malloc(sizeof(EVENT));

    if (novi == 0)
    {
        return;
    }
    strcpy(novi->IDDogadjaja, IDDogadjaja);

    novi->next = *event;
    *event = novi;
}

int ukloniDogadjaj(FILE* fp, EVENT* event)
{
    if (fp = fopen("Blokirani.txt", "w"))
    {
        while (event != 0)
        {
            fprintf(fp, "%s\n", event->IDDogadjaja);
            event = event->next;
        }
        fclose(fp);
        return 1;
    }
    else
    {
        printf("Neuspjesno otvaranje datoteke za pisanje.\n");
        return 0;
    }
}

void brisi(EVENT** event)
{
    while (*event)
    {
        EVENT* temp;
        temp = *event;
        *event = temp->next;
        free(temp);
    }
}