#include <stdio.h>
#include <string.h>
#define MAX 20
void PronadjiUlaznice(struct Datum datum,char* naziv)
{
    FILE* fp;
    FILE* fp1;
    char ime[20]="";
    char sifra[20]="";
    int flag=0;
    if (fp = fopen("Ulaznice.txt", "r"))
    {
        DOGADJAJ pom;
        if(fp1=fopen("IzvjestajProdaje.txt","w"))
        {
            while(fscanf(fp, "%s %s %s %d.%d.%d %d:%d %s %d %d %d %s \n",sifra,pom.ID, pom.naziv, &pom.datum.dan,
                         &pom.datum.mjesec, &pom.datum.godina, &pom.vrijeme.sat, &pom.vrijeme.minut, pom.mjesto,
                         &pom.cijena_ulaznice, &pom.broj_mjesta, &pom.broj_prodatih_ulaznica, ime))
            {
                if(strcmp(naziv,pom.naziv)==0 && pom.datum.godina==datum.godina && pom.datum.dan==datum.dan && pom.datum.mjesec==datum.mjesec)
                {
                    flag=1;
                    fprintf(fp1, "%s %s %s %d.%d.%d %d:%d %s %d %d %d %s \n",sifra,pom.ID, pom.naziv, pom.datum.dan,
                            pom.datum.mjesec, pom.datum.godina, pom.vrijeme.sat, pom.vrijeme.minut, pom.mjesto,
                            pom.cijena_ulaznice, pom.broj_mjesta, pom.broj_prodatih_ulaznica, ime);
                }
            }
            if(flag==0)printf("Nema kupljenih ulaznica za ovaj dogadjaj!\n");
            fclose(fp1);
        }



        fclose(fp);
    }
}
void KreiranjeIzvjestaja()
{
    char[MAX] naziv;
    printf("Unesite naziv dogadjaja:");
    scanf("%s",naziv);
    printf("Unesite vrijeme tog dogadjaja:");
    struct Datum datum;
    scanf("%d",&datum.dan);
    scanf("%d",&datum.mjesec);
    scanf("%d",&datum.godina);
    PronadjiUlaznice(datum,naziv);
}
