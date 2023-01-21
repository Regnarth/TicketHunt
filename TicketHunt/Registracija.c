#include <stdio.h>
#include <string.h>
#include "Registracija.h"
#include "LoadConfig.h"
void register_user()
{
    USER user;
    FILE* fp;
    printf("Enter a username: ");
    scanf("%s", user.username);
    if (!provjeriUsername(user.username))
    {
        if (fp = fopen(concat(CONFIG_DEV_FOLDER,"Korisnici.txt"), "a+"))
        {

            printf("Enter your name: ");
            scanf("%s", user.ime);
            printf("Enter your lastname: ");
            scanf("%s", user.prezime);
            printf("Enter a password: ");
            scanf("%s", user.password);
            fprintf(fp, "%s %s %s %s\n", user.ime, user.prezime, user.username, user.password);
            fclose(fp);
        }
        else printf("Neuspjesno otvoren fajl!");


    }
    else printf("Odabrali ste postojece korisnicko ime!");
}

int provjeriUsername(char* username)
{
    int size = 1;
    USER pom;
    FILE* fp;
    int i = 0;
    if (fp = fopen(concat(CONFIG_DEV_FOLDER,"Korisnici.txt"), "r"))
    {
        while (fscanf(fp, "%s %s %s %s", pom.ime, pom.prezime, pom.username, pom.password) != EOF)
        {
            if (strcmp(username, pom.username) == 0) {
                fclose(fp);
                return 1;
            }
        }
        fclose(fp);
    }
    if (fp = fopen(concat(CONFIG_DEV_FOLDER,"Administratori.txt"), "r"))
    {
        while (fscanf(fp, "%s %s %s %s", pom.ime, pom.prezime, pom.username, pom.password) != EOF)
        {
            if (strcmp(username, pom.username) == 0)return 1;
        }
        fclose(fp);
    }
    if (fp = fopen(concat(CONFIG_DEV_FOLDER,"Klijenti.txt"), "r"))
    {
        while (fscanf(fp, "%s %s %s %s", pom.ime, pom.prezime, pom.username, pom.password) != EOF)
        {
            if (strcmp(username, pom.username) == 0)return 1;
        }
        fclose(fp);
    }
    return 0;
}
