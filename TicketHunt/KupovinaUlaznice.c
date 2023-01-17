#include <stdio.h>
#include <string.h>
#define MAX 20
typedef struct User USER;
void ispisDogadjaja(DOGADJAJ* pom)
{
    printf("%s %d %d %d %s %d %d %d %s",pom->naziv,pom->datum.dan,pom->datum.mjesec,pom->datum.godina,pom->mjesto,pom->vrijeme.sat,pom->vrijeme.minut,pom->cijena_ulaznice,pom->opis_dogadjaja);
}
void unosImena(DOGADJAJ* pom) {} //zavrsiti
void KupovinaUlaznice(USER* korisnik)
{
    DOGADJAJ pom;
    do
    {
        unosPodataka(&pom);
    }
    while(!provjeraPostojanja(pom));
    ispisDogadjaja(&pom);
    char ime[MAX]="";
    if(provjeraKupovanjaNaIme(pom))
    {
        printf("Unesite Vase ime: ");
        scanf("%s",ime);
    }
    if(nacinPreuzimanja()==1)printf("Preuzmite vasu ulaznicu na adresi: ul. Mihajla Seve 23");else; // preuzimanje
    else ispisDogadjaja(&pom);
    if( provjeraRasprodanosti())
    {
        printf("Ulaznice za ovaj dogadjaj su rasprodate!\n");
    }
    else
    {
        
        if(korisnik->kredit>=pom.cijena_ulaznice)
        {
            korisnik->kredit-=pom.cijena_ulaznice;
            memorisanjeUlaznice(&pom,korisnik,ime);
            printf("Uspjesna kupovina: %s %s %d.%d.%d.%d %d:%d %d",ime,pom.naziv,pom.datum.dan,pom.datum.mjesec,pom.datum.godina,pom.vrijeme.sat,pom.vrijeme.minut,pom.cijena_ulaznice);
        }
        else
        {
            printf("Nedovoljno kredita na racunu!");
        }


    }

}

void unosPodataka(DOGADJAJ* dogadjaj)
{
    int naziv_validan=0;
    while(naziv_validan==0)
    {
        printf("Unesite naziv dogadjaja:");
        scanf("%s", dogadjaj->naziv);

        if (validacijaNaziva(dogadjaj->naziv)==1)
        {
            naziv_validan=1;
        }

    }
    printf("Unesite mjesto odrzavanja:");
    gets(dogadjaj->mjesto);

    int datum_validan=0;
    while(datum_validan==0)
    {
        printf("Datum dogadjaja(dd mm yyyy):");
        scanf("%d %d %d", &dogadjaj->datum.dan, &dogadjaj->datum.mjesec, &dogadjaj->datum.godina);

        if (validacijaDatuma(dogadjaj->datum.dan, dogadjaj->datum.mjesec, dogadjaj->datum.godina)==1)
        {
            datum_validan=1;
        }

    }
    int vrijeme_validno=0;
    while(vrijeme_validno==0)
    {
        printf("Unesite vrijeme dogadjaja(hh mm):");
        scanf("%d %d", &dogadjaj->vrijeme.sat, &dogadjaj->vrijeme.minut);

        if (validacijaVremena(dogadjaj->vrijeme.sat, dogadjaj->vrijeme.minut)==1)
        {
            vrijeme_validno=1;
        }

    }
}
int provjeraPostojanja(DOGADJAJ* dogadjaj)
{
    FILE* fp;
    if (fp = fopen("Dogadjaji.txt", "r"))
    {
        DOGADJAJ temp;

        while (fscanf(fp, "%s %d.%d.%d %d:%d %s %d %d %d %d\n", temp.naziv, &temp.datum.dan,
                      &temp.datum.mjesec, &temp.datum.godina, &temp.vrijeme.sat, &temp.vrijeme.minut, temp.mjesto,
                      &temp.cijena_ulaznice, &temp.broj_mjesta, &temp.broj_prodatih_ulaznica, &temp.kupuje_na_ime) == 11)
        {
            if (strcmp(dogadjaj->naziv, temp.naziv) == 0)
            {
                printf("%s %d.%d.%d %d:%d %s %d %d %d %d\n",temp.naziv,temp.datum.dan,temp.datum.mjesec,temp.datum.godina,temp.vrijeme.sat, temp.vrijeme.minut, temp.mjesto,
                      temp.cijena_ulaznice, temp.broj_mjesta, temp.broj_prodatih_ulaznica, temp.kupuje_na_ime);
                return 1;
            }
        }
        fclose(fp);
    }
    return 0;
}

int provjeraKupovanjaNaIme(DOGADJAJ* dogadjaj)
{
    FILE* fp;
    if (fp = fopen("Dogadjaji.txt", "r"))
    {
        DOGADJAJ temp;

        while (fscanf(fp, "%s %d.%d.%d %d:%d %s %d %d %d %d\n", temp.naziv, &temp.datum.dan,
                      &temp.datum.mjesec, &temp.datum.godina, &temp.vrijeme.sat, &temp.vrijeme.minut, temp.mjesto,
                      &temp.cijena_ulaznice, &temp.broj_mjesta, &temp.broj_prodatih_ulaznica, &temp.kupuje_na_ime) == 11)
        {
            if (temp.kupuje_na_ime == 1)
            {
                return 1;
            }
        }
        fclose(fp);
    }
    return 0;
}

int nacinPreuzimanja()
{
    int pom;
    do
    {
        printf("Ulaznice zelite da preuzmete: 1 (Licno) , 2 (Elektronski)");
        scanf("%d",&pom);
    }
    while(pom!=1 || pom!=2);
    return pom;
}
int provjeraRasprodanosti()
{
    FILE* fp;
    if (fp = fopen("Dogadjaji.txt", "r"))
    {
        DOGADJAJ temp;

        while (fscanf(fp, "%s %d.%d.%d %d:%d %s %d %d %d %d\n", temp.naziv, &temp.datum.dan,
                      &temp.datum.mjesec, &temp.datum.godina, &temp.vrijeme.sat, &temp.vrijeme.minut, temp.mjesto,
                      &temp.cijena_ulaznice, &temp.broj_mjesta, &temp.broj_prodatih_ulaznica, &temp.kupuje_na_ime) == 11)
        {
            if (temp.broj_prodatih_ulaznica == temp.broj_mjesta)
            {
                return 1;
            }
        }
        fclose(fp);
    }
    return 0;
}

void memorisanjeUlaznice(DOGADJAJ* pom,char* ime)
{   static int sifra=0;
    FILE* fp;
    if (fp = fopen("Ulaznice.txt", "w"))
    {
        if(pom->kupuje_na_ime==1)
        {
            fprintf(fp, "%s %s %s %d.%d.%d %d:%d %s %d %d %d %s \n",sifra,pom->ID, pom->naziv, pom->datum.dan,
                    pom->datum.mjesec, pom->datum.godina, pom->vrijeme.sat, pom->vrijeme.minut, pom->mjesto,
                    pom->cijena_ulaznice, pom->broj_mjesta, pom->broj_prodatih_ulaznica, ime);
        }
        else fprintf(fp, "%s %s %s %d.%d.%d %d:%d %s %d %d %d %s \n",sifra, pom->ID, pom->naziv, pom->datum.dan,
                         pom->datum.mjesec, pom->datum.godina, pom->vrijeme.sat, pom->vrijeme.minut, pom->mjesto,
                         pom->cijena_ulaznice, pom->broj_mjesta, pom->broj_prodatih_ulaznica, "Bez Imena" );
        fclose(fp);
    }
    if(fp=fopen("SifraKorisnicko.txt","w")){
        if(pom->kupuje_na_ime==1){
            fprintf(fp,"%s %s \n",sifra, ime);
            else fprintf(fp"%s %s",sifra, "Bez imena");
        }
        fclose(fp);
    }
   sifra++;
}
