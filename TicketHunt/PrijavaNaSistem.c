#include "PrijavaNaSistem.h"
#include "SuspendovanjeNaloga.h"
#include "PonistavanjeSifre.h"
#include"PromjenaSifre.h"
#include "Registracija.h"
#include "LoadConfig.h"

int prebrojiPrijavljeneNaloge()
{
	char file[50] = "Prijavljeni korisnici.txt";
	int br = 0;
	FILE* f = 0;
	if (f = fopen(concat(CONFIG_DEV_FOLDER, file), "r"))
	{
		PRIJAVLJEN p;
		while (fscanf(f, " %s %s %d %d", p.korisnickoIme, p.sifra, &p.brPrijava, &p.odjavljen) != EOF)  br++;
		fclose(f);
	}
	else printf("Neuspjesno otvaranje datoteke\n");
	return br;
}
int provjeraIkadPrijavljen(FILE* f, char* korIme) {

	if (f = fopen(concat(CONFIG_DEV_FOLDER, "Prijavljeni korisnici.txt"), "r")) {
		PRIJAVLJEN p;

		while (fscanf(f, "%s %s %d %d", p.korisnickoIme, p.sifra, &p.brPrijava, &p.odjavljen) == 4) {
			if (strcmp(korIme, p.korisnickoIme) == 0) {
				fclose(f);
				return 1;
			}
		}
		fclose(f);
	}

	return 0;

}
int provjeraIspravnostiSifre(char* file, char* korIme, char* sifra)
{
	FILE* f = 0;
	if (f = fopen(concat(CONFIG_DEV_FOLDER, file), "r"))
	{
		KORISNIK k;
		while (fscanf(f, "%s %s %s %s", k.ime, k.prezime, k.korisnickoIme, k.sifra) == 4) {
			if (strcmp(korIme, k.korisnickoIme) == 0)break;
		}
		if (strcmp(korIme, k.korisnickoIme) == 0 && strcmp(sifra, k.sifra) == 0)
		{
			fclose(f);
			return 1;
		}
		return  0;
	}
	else return printf("Neuspjesno otvaranje datoteke\n"), 0;
}
int provjeraPonistavanjaSifre(char* korIme)
{
	FILE* f = 0;
	if (f = fopen(concat(CONFIG_DEV_FOLDER, "PonisteneSifre.txt"), "r"))
	{
		char korisnickoIme[MAX];
		while (fscanf(f, "%s", korisnickoIme) == 1)
			if (strcmp(korIme, korisnickoIme) == 0)
			{
				fclose(f);
				return 1;
			}
		return 0;
	}
	else return 0;
}
int ocitajBrojPrijava(char* korIme)
{
	PRIJAVLJEN p;
	p.brPrijava = 0;
	FILE* f = 0;
	if (f = fopen(concat(CONFIG_DEV_FOLDER, "Prijavljeni korisnici.txt"), "r")) {
		while (fscanf(f, " %s %s %d %d", p.korisnickoIme, p.sifra, &p.brPrijava, &p.odjavljen) == 4)
			if (strcmp(korIme, p.korisnickoIme) == 0)break;
		fclose(f);
		return p.brPrijava;
	}
	else return printf("Neuspjesno otvaranje datoteke\n"), 0;
}
int nulirajBrojPrijava(char* korIme)
{
	FILE* f = 0, * f1 = 0;
	PRIJAVLJEN p;
	if (f = fopen(concat(CONFIG_DEV_FOLDER, "Prijavljeni korisnici.txt"), "r"))
	{
		if (f1 = fopen(concat(CONFIG_DEV_FOLDER, "pom.txt"), "w")) {
			while (fscanf(f, "%s %s %d %d", p.korisnickoIme, p.sifra, &p.brPrijava, &p.odjavljen) == 4) {
				if (strcmp(korIme, p.korisnickoIme) == 0) {
					fprintf(f1, "%s %s %d %d", p.korisnickoIme, p.sifra, 0, p.odjavljen);
				}
				else {
					fprintf(f1, "%s %s %d %d", p.korisnickoIme, p.sifra, p.brPrijava, p.odjavljen);
				}
			}
			fclose(f1);
		}

		else {

			fclose(f);
			return 0;
		}
		fclose(f);
	}
	else return 0;
	if (remove(concat(CONFIG_DEV_FOLDER, "Prijavljeni korisnici.txt")) != 0) printf("ne radi remove.\n");
	rename(concat(CONFIG_DEV_FOLDER, "pom.txt"), concat(CONFIG_DEV_FOLDER, "Prijavljeni korisnici.txt"));
	return 1;
}

int azurirajBrojPrijava(char* korIme)
{
	char file[50] = "Prijavljeni korisnici.txt";
	FILE* f = 0, * f1 = 0;
	PRIJAVLJEN p;
	if (f = fopen(concat(CONFIG_DEV_FOLDER, "Prijavljeni korisnici.txt"), "r"))
	{
		if (f1 = fopen(concat(CONFIG_DEV_FOLDER, "pomocna.txt"), "w")) {
			while (fscanf(f, "%s %s %d %d", p.korisnickoIme, p.sifra, &p.brPrijava, &p.odjavljen) == 4) {
				if (strcmp(korIme, p.korisnickoIme) == 0) {
					fprintf(f1, "%s %s %d %d", p.korisnickoIme, p.sifra, p.brPrijava + 1, p.odjavljen);
				}
				else {
					fprintf(f1, "%s %s %d %d", p.korisnickoIme, p.sifra, p.brPrijava, p.odjavljen);
				}
			}
			fclose(f1);
		}

		else {

			fclose(f);
			return 0;
		}
		fclose(f);
	}
	else return 0;
	if (remove(concat(CONFIG_DEV_FOLDER, "Prijavljeni korisnici.txt")) != 0) printf("ne radi remove.\n");
	rename(concat(CONFIG_DEV_FOLDER, "pomocna.txt"), concat(CONFIG_DEV_FOLDER, "Prijavljeni korisnici.txt"));
	return 1;
}
int azurirajStatus(char* korIme)
{
	char file[50] = "Prijavljeni korisnici.txt";

	FILE* f = 0, * f1 = 0;
	PRIJAVLJEN p;

	if (f = fopen(concat(CONFIG_DEV_FOLDER, file), "r"))
	{
		if (f1 = fopen(concat(CONFIG_DEV_FOLDER, "status.txt"), "w")) {
			while (fscanf(f, "%s %s %d %d", p.korisnickoIme, p.sifra, &p.brPrijava, &p.odjavljen) == 4) {
				if (strcmp(korIme, p.korisnickoIme) == 0) {
					if (p.odjavljen == 1) {
						fprintf(f1, "%s %s %d %d\n", p.korisnickoIme, p.sifra, p.brPrijava, 0);
					}
					else fprintf(f1, "%s %s %d %d\n", p.korisnickoIme, p.sifra, p.brPrijava, p.odjavljen);
				}
				else fprintf(f1, "%s %s %d %d\n", p.korisnickoIme, p.sifra, p.brPrijava, p.odjavljen);


			} fclose(f1);
		}
		else {
			fclose(f);
			return 0;
		}
		fclose(f);
	}
	else return 0;

	remove(concat(CONFIG_DEV_FOLDER, "Prijavljeni korisnici.txt"));
	rename(concat(CONFIG_DEV_FOLDER, "status.txt"), concat(CONFIG_DEV_FOLDER, "Prijavljeni korisnici.txt"));
	return 1;
}
int prijava(char* file, USER* user)
{
	FILE* f = 0;
	char korIme[MAX], sifra[MAX];

	do
	{
		printf("Unesite korisnicko ime\n");
		scanf("%s", korIme);
		//gets(korIme);
		if (provjeraPostojanjaKorImena(file, korIme) != 1)printf("Unijeli ste pogresno korisnicko ime\n");
	} while (provjeraPostojanjaKorImena(file, korIme) != 1);
	do
	{
		printf("Unesite sifru\n");
		scanf("%s", sifra);
		if (provjeraIspravnostiSifre(file, korIme, sifra) != 1)printf("Unijeli ste pogresnu sifru\n");
	} while (provjeraIspravnostiSifre(file, korIme, sifra) != 1);
	if (provjeraSuspenzije(f, korIme))return printf("Nalog je suspendovan. Prijava nije moguca."), 0;
	if (provjeraPonistavanjaSifre(korIme))return printf("Vasa sifra je ponistena. Prijava nije moguca.\n"), 0;
	strcpy(user->username, korIme);
	strcpy(user->password, sifra);
	if (!provjeraIkadPrijavljen(f, korIme))
	{
		if (f = fopen(concat(CONFIG_DEV_FOLDER, "Prijavljeni korisnici.txt"), "a"))
		{
			fprintf(f, "%s %s %d %d\n", user->username, user->password, 1, 0);
			fclose(f);
			return 1;
		}
		else return printf("Neuspjesno otvaranje datoteke"), 0;
	}
	if (azurirajBrojPrijava(korIme))
	{
		if (ocitajBrojPrijava(korIme) >= CONFIG_N)
		{
			mijenjajSifru(user);
			nulirajBrojPrijava(korIme);
		}
		if (azurirajStatus(korIme))
			return 1;
	}
	return 0;
}
int prijavaNaSistem(USER* user)
{
	user->vrstaNaloga = birajVrstuNaloga();
	if (user->vrstaNaloga == 1)
	{
		FILE* f = 0;
		char c = 0;
		char s1[100] = "", s2[100] = "";
		USER pom;
		if (f = fopen(concat(CONFIG_DEV_FOLDER, "PrviAdministrator.txt"), "r")) {
			fscanf(f, "%s %s %c", s1, s2, &c);
			fclose(f);
		}
		printf("%c", c);
		if (c == '_') {
			if (prviAdministrator(user))
				return 1;
			else return 0;
		}
		else if (c == 0) return 0;
		else {
			if (prijava("Administratori.txt", user))return 1;
		}
	}


	else if (user->vrstaNaloga == 2)
	{
		if (prijava("Klijenti.txt", user))return 1;
	}
	else if (user->vrstaNaloga == 3)
	{
		if (prijava("Korisnici.txt", user))return 1;
	}
	else return 0;
}
