#include <stdio.h>
#include <string.h>
#include "PregledNaloga.h"
#include "Registracija.h"
#include "LoadConfig.h"
void pregledNaloga() {
    FILE* fp;
    printf("Klijenti:\n");
    if (fp = fopen(concat(CONFIG_DEV_FOLDER,"Klijenti.txt"), "r")) {
        USER pom;
        while (fscanf(fp, "%s %s %s %s", pom.ime, pom.prezime, pom.username, pom.password) != EOF) {
            printf("%s %s %s %s\n", pom.ime, pom.prezime, pom.username, pom.password);
        }
        fclose(fp);
    }
    printf("Administratori:\n");
    if (fp = fopen(concat(CONFIG_DEV_FOLDER,"Administratori.txt"), "r")) {
        USER pom;
        while (fscanf(fp, "%s %s %s %s", pom.ime, pom.prezime, pom.username, pom.password) != EOF) {
            printf("%s %s %s %s\n", pom.ime, pom.prezime, pom.username, pom.password);
        }
        fclose(fp);
    }
    printf("Korisnici:\n");
    if (fp = fopen(concat(CONFIG_DEV_FOLDER,"Korisnici.txt"), "r")) {
        USER pom;
        while (fscanf(fp, "%s %s %s %s", pom.ime, pom.prezime, pom.username, pom.password) != EOF) {
            printf("%s %s %s %s\n", pom.ime, pom.prezime, pom.username, pom.password);
        }
        fclose(fp);
    }
}