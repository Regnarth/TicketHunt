#include"PregledListeDogadjaja.h"
int prebrojiDogadjaje(char *file)
{
	int br = 0;
	FILE* f =0;
	if (f = fopen(file, "r"))
	{
		DOGADJAJ d;
		while (fscanf(f,"%s %d.%d.%d %d:%d %s %d %d %d %d %s\n", d.naziv, &d.datum.dan,
                 &d.datum.mjesec, &d.datum.godina, &d.vrijeme.sat, &d.vrijeme.minut, d.mjesto,
                 &d.cijena_ulaznice, &d.broj_mjesta, &d.broj_prodatih_ulaznica, &d.kupuje_na_ime, d.ID) != EOF)  br++;
		fclose(f);
	}
	else printf("Neuspjesno otvaranje datoteke");
	return br;
}
void dodaj(CVOR** dogadjaj, char* naziv) {

	CVOR* novi = (CVOR*)malloc(sizeof(CVOR));

	if (!novi) return;

	strcpy(novi->naziv, naziv);

	novi->sljedeci = *dogadjaj;
	*dogadjaj = novi;
}
CVOR* trazi(CVOR *dogadjaj, char *naziv) {
  while (dogadjaj && strcmp(dogadjaj->naziv, naziv) < 0)
    dogadjaj = dogadjaj->sljedeci;
  return dogadjaj == 0 || strcmp(dogadjaj->naziv, naziv) > 0 ? 0 : dogadjaj;
}
void pisi(CVOR *dogadjaj) {
  while (dogadjaj)
  {
    printf(" %s\n",
      dogadjaj->naziv);
    dogadjaj = dogadjaj->sljedeci;
  }
}
void brisi_listu(CVOR **dogadjaj) {
  while (*dogadjaj) {
    CVOR *p = (*dogadjaj)->sljedeci;
    free(*dogadjaj);
    *dogadjaj= p;
  }
}

void pregledListeDogadjaja(char *file)
{
 if(!prebrojiDogadjaje(file))printf("Ne postoji nijedan dogadjaj\n");
 else
 {
     CVOR *dogadjaj=0;
      FILE* f=0;
    if (f = fopen(file, "r"))
    {
        DOGADJAJ temp;
        while (  fscanf(f, "%s %d.%d.%d %d:%d %s %d %d %d %d %s\n", temp.naziv, &temp.datum.dan,
                 &temp.datum.mjesec, &temp.datum.godina, &temp.vrijeme.sat, &temp.vrijeme.minut, temp.mjesto,
                 &temp.cijena_ulaznice, &temp.broj_mjesta, &temp.broj_prodatih_ulaznica, &temp.kupuje_na_ime, temp.ID)   !=  EOF )
                 {
                   if(!trazi(dogadjaj,temp.naziv))
                   dodaj(&dogadjaj,temp.naziv);
                 }
                 fclose(f);
                 pisi(dogadjaj);
                 brisi_listu(&dogadjaj);
 }
 else printf("Neuspjesno otvaranje datoteke");
}
}
