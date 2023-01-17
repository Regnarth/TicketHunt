#include <stdio.h>
#include <string.h>
#include "PregledNaloga.h"
#include "Registracija.h"

void pregledNaloga(){
FILE* fp;
if(fp=fopen("Klijenti.txt","r")){
    USER pom;
    while(fscanf(fp,"%s %s %s %s",pom.ime,pom.prezime,pom.username,pom.password)!=EOF){
        printf("%s %s %s %s\n",pom.ime,pom.prezime,pom.username,pom.password);
    }
    fclose(fp);
}
if(fp=fopen("Administratori.txt","r")){
    USER pom;
    while(fscanf(fp,"%s %s %s %s",pom.ime,pom.prezime,pom.username,pom.password)!=EOF){
        printf("%s %s %s %s\n",pom.ime,pom.prezime,pom.username,pom.password);
    }
    fclose(fp);
}
    if(fp=fopen("Korisnici.txt","r")){
    USER pom;
    while(fscanf(fp,"%s %s %s %s",pom.ime,pom.prezime,pom.username,pom.password)!=EOF){
        printf("%s %s %s %s\n",pom.ime,pom.prezime,pom.username,pom.password);
    }
    fclose(fp);
}
}
