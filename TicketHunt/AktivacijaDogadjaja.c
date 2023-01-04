#include "AktivacijaDogadjaja.h"
#include "BlokiranjeDogadjaja.h"

void aktivirajDogadjaj()
{
    char imeDogadjaja[MAX_EVENT_NAME_LENGHT];
    printf("Unesite ime dogadjaja koji zelite da aktivirate:\n");
    gets(imeDogadjaja);
    FILE* fp;
    while (provjeraAktivnostiDogadjaja(fp, imeDogadjaja) == 0)
    {
        printf("Dogadjaj nije blokiran.\n");
        return;
    }

    EVENT* event = 0;
    if (fp = fopen("Blokirani.txt", "r"))
    {
        char temp[MAX_EVENT_NAME_LENGHT];
        while (fgets(temp, 50, fp))
        {
            if (strcmp(temp, imeDogadjaja) != 0)
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
void dodaj(EVENT** event, char* imeDogadjaja)
{
    EVENT* novi = (EVENT*)malloc(sizeof(EVENT));

    if (novi == 0)
    {
        return;
    }
    strcpy(novi->imeDogadjaja, imeDogadjaja);

    novi->next = *event;
    *event = novi;
}

int ukloniDogadjaj(FILE* fp, EVENT* event)
{
    if (fp = fopen("Blokirani.txt", "w"))
    {
        while (event != 0)
        {
            fprintf(fp, "%s\n", event->imeDogadjaja);
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