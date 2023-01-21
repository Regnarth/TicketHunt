#include "PromjenaSifre.h"
#include "Registracija.h"
#include "LoadConfig.h"
#define LEN 8
static int provjeraDuzineSifre(char* sifra)
{
	if (strlen(sifra) < LEN)
		return 0;
	else return 1;
}
static int provjeraPostojanjaBroja(char* sifra)
{
	int br = 0;
	for (int i = 0; i < strlen(sifra); i++)
	{
		if (('0' <= sifra[i]) && (sifra[i] <= '9'))
			br++;
	}
	if (br == 0)
		return 0;
	else return 1;
}
static int provjeraPostojanjaVelikogSlova(char* sifra)
{
	int br = 0;
	for (int i = 0; i < strlen(sifra); i++)
	{
		if (isupper(sifra[i]))
			br++;
	}
	if (br == 0)
		return 0;
	else return 1;
}
static int provjera(char* sifra, char* novaSifra)
{
	if ((provjeraDuzineSifre(novaSifra) == 0) && (provjeraPostojanjaBroja(novaSifra) == 0) && (provjeraPostojanjaVelikogSlova(novaSifra) == 0)) { printf("Sifra je prekratka. Vasa sifra mora da sadrzi bar jedan broj i bar jedno veliko slovo.\n\n"); return 0; }
	if ((provjeraDuzineSifre(novaSifra) == 1) && (provjeraPostojanjaBroja(novaSifra) == 1) && (provjeraPostojanjaVelikogSlova(novaSifra) == 0)) { printf(" Vasa sifra mora da sadrzi bar jedno veliko slovo.\n\n"); return 0; }
	if ((provjeraDuzineSifre(novaSifra) == 1) && (provjeraPostojanjaBroja(novaSifra) == 0) && (provjeraPostojanjaVelikogSlova(novaSifra) == 1)) { printf(" Vasa sifra mora da sadrzi bar jedan broj.\n\n"); return 0; }
	if ((provjeraDuzineSifre(novaSifra) == 0) && (provjeraPostojanjaBroja(novaSifra) == 1) && (provjeraPostojanjaVelikogSlova(novaSifra) == 1)) { printf("Sifra je prekratka.\n\n"); return 0; }
	if ((provjeraDuzineSifre(novaSifra) == 1) && (provjeraPostojanjaBroja(novaSifra) == 0) && (provjeraPostojanjaVelikogSlova(novaSifra) == 0)) { printf(" Vasa sifra mora da sadrzi bar jedan broj i bar jedno veliko slovo.\n\n"); return 0; }
	if ((provjeraDuzineSifre(novaSifra) == 0) && (provjeraPostojanjaBroja(novaSifra) == 0) && (provjeraPostojanjaVelikogSlova(novaSifra) == 1)) { printf("Sifra je prekratka. Vasa sifra mora da sadrzi bar jedan broj.\n\n"); return 0; }
	if ((provjeraDuzineSifre(novaSifra) == 0) && (provjeraPostojanjaBroja(novaSifra) == 1) && (provjeraPostojanjaVelikogSlova(novaSifra) == 0)) { printf("Sifra je prekratka. Vasa sifra mora da sadrzi bar jedno veliko slovo.\n\n"); return 0; }
	if (strcmp(sifra, novaSifra) == 0) printf("Unijeli ste trenutnu sifra. Molimo Vas da unesete drugu sifra.\n\n"); else return 1;

}
int birajVrstuNaloga() {
	int vrstaNaloga;
	//char c;
	int broj;
	do
	{
		printf("Unesite odgovarajuci broj da biste izabrali vrstu naloga:\n");
		printf("1. Administrator\n2. Klijent\n3. Korisnik\n");
		scanf("%d", &broj);
		//gets(c);
		//vrstaNaloga = atoi(c);
	} while (broj < 1 || broj>3);
	return broj;
}
int prebrojiNaloge(char* file)
{
	int br = 0;
	FILE* f = 0;
	if (f = fopen(concat(CONFIG_DEV_FOLDER,file), "r"))
	{
		KORISNIK k;
		while (fscanf(f, " %s %s %s %s", k.ime, k.prezime, k.korisnickoIme, k.sifra) != EOF)  br++;
		fclose(f);
	}
	else printf("Neuspjesno otvaranje datoteke");
	return br;
}
int provjeraPostojanjaKorImena(char* file, char* korIme)
{
	KORISNIK k;
	int bru = prebrojiNaloge(file);
	KORISNIK* niz = (KORISNIK*)malloc(bru * sizeof(KORISNIK));
	FILE* f = 0;
	int i = 0;
	if (f = fopen(concat(CONFIG_DEV_FOLDER,file), "r"))
	{
		while (fscanf(f, "%s %s %s %s", niz[i].ime, niz[i].prezime, niz[i].korisnickoIme, niz[i].sifra) != EOF) {
			//printf("%s", niz[i].korisnickoIme);
			if (strcmp(korIme, niz[i].korisnickoIme) == 0) {
				fclose(f);
				return 1;
			}
			i++;
		}
		fclose(f);
		free(niz);
		return 0;
	}
	else return 0;
}
int promjenaSifre(char* file, USER* user)
{
	KORISNIK k;
	char korIme[MAX], staraSifra[MAX], korisnickoIme[MAX], novaSifra[MAX];
	int bri = 0;
	int bru = prebrojiNaloge(file);
	KORISNIK* niz = (KORISNIK*)malloc(bru * sizeof(KORISNIK));
	do
	{
		printf("Unesite korisnicko ime\n");
		scanf("%s", korIme);
		if (provjeraPostojanjaKorImena(file, korIme) != 1)printf("Unijeli ste pogresno korisnicko ime\n");
	} while (provjeraPostojanjaKorImena(file, korIme) != 1);
	printf("Unesite trenutnu sifru\n");
	scanf("%s", staraSifra);
	FILE* f;
	if (f = fopen(concat(CONFIG_DEV_FOLDER,file), "r"))
	{
		while (fscanf(f, "%s %s %s %s", niz[bri].ime, niz[bri].prezime, niz[bri].korisnickoIme, niz[bri].sifra) == 4) {
			if (strcmp(korIme, niz[bri].korisnickoIme) == 0)break;
			bri++;
		}
		int k = bri + 1;
		while (fscanf(f, "%s %s %s %s", niz[k].ime, niz[k].prezime, niz[k].korisnickoIme, niz[k].sifra) != EOF)k++;
		fclose(f);
	}
	else printf("Neuspjesno otvaranje datoteke");
	if (strcmp(korIme, niz[bri].korisnickoIme) != 0 || strcmp(niz[bri].sifra, staraSifra) != 0)
	{
		printf("Unijeli ste pogresnu sifru\n");
		do
		{
			printf("Unesite trenutnu sifru\n");
			scanf("%s", staraSifra);
		} while (strcmp(korIme, niz[bri].korisnickoIme) != 0 || strcmp(niz[bri].sifra, staraSifra) != 0);
	}
	if (strcmp(korIme, niz[bri].korisnickoIme) == 0 && strcmp(niz[bri].sifra, staraSifra) == 0) {
		do
		{
			printf("Unesite novu sifru.Sifra mora imati minimum 8 znakova od kojih bar jedan mora biti broj i bar jedan veliko slovo.\n");
			scanf("%s", novaSifra);
		} while (provjera(staraSifra, novaSifra) == 0);
		if (f = fopen(concat(CONFIG_DEV_FOLDER,file), "w"))
		{
			for (int i = 0; i < bri; i++)
				fprintf(f, "%s %s %s %s\n", niz[i].ime, niz[i].prezime, niz[i].korisnickoIme, niz[i].sifra);
			fprintf(f, "%s %s %s %s\n", niz[bri].ime, niz[bri].prezime, niz[bri].korisnickoIme, novaSifra);
			for (int j = bri + 1; j < bru; j++)
				fprintf(f, "%s %s %s %s\n", niz[j].ime, niz[j].prezime, niz[j].korisnickoIme, niz[j].sifra);
			fclose(f);
			strcpy(user->password, novaSifra);
			return 1;
		}
		else return 0;

		free(niz);
	}
}
void mijenjajSifru(USER* user)
{
	if (user->vrstaNaloga == 1)
	{
		if (promjenaSifre("Administratori.txt", user))printf("Sifra uspjesno promjenjena");
	}
	else if (user->vrstaNaloga == 2)
	{
		if (promjenaSifre("Klijenti.txt", user))printf("Sifra uspjesno promjenjena");
	}
	else if (user->vrstaNaloga == 3)
	{
		if (promjenaSifre("Korisnici.txt", user))printf("Sifra uspjesno promjenjena");
	}
}
