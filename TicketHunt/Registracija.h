#ifndef REGISTRACIJA_H
#define REGISTRACIJA_H
// REGISTRACIJA_H

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

struct User {
    char ime[MAX_USERNAME_LENGTH];
    char prezime[MAX_USERNAME_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int kredit;
    int vrstaNaloga;
};
typedef struct User USER;

void register_user();
int provjeriUsername(char* username);

#endif
