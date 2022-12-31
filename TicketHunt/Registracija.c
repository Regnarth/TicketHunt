#include <stdio.h>
#include <string.h>
#include "Registracija.h"

void register_user()
{
    struct User user;
    FILE* fp;
    int pom;
    printf("Enter a username: ");
    fgets(user.username, MAX_USERNAME_LENGTH, stdin);
    if(provjeriUsername(user.username))
    {
        if(fp=fopen("Korisnici.txt","w"))
        {
            fprintf(fp,"%s",user.username);
            printf("Enter a password: ");
            fgets(user.password, MAX_PASSWORD_LENGTH, stdin);
            fprintf(fp,"%s",user.password);
        }else printf("Neuspjesno otvoren fajl!");


    }
}

int provjeriUsername(char* username){
FILE *fp;
char pom[MAX_USERNAME_LENGTH];
if(fp=fopen("Korisnici.txt","w")){
  fscanf(fp,"%s",pom);
  if(strcmp(pom,username)==0)return 1;
} else printf("Neuspjesno otvoren fajl!");
return 0;
}
