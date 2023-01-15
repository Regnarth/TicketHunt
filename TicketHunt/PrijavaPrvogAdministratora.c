#include "PrijavaPrvogAdministratora.h"
#include "KreiranjeNaloga.h"

void prviAdministrator() {

	ADMINISTRATOR administrator;

	char korisnickoIme[MAX];
	char sifra[MAX];
	FILE* f = 0;
	if (f = fopen("PrviAdministrator.txt", "r")) {
		fscanf(f, "%s %s", korisnickoIme, sifra);
		fclose(f);
	}
	else {
		printf("Neuspjesno otvaranje datoteke.\n");
		printf("Neuspjela prijava.\n");
		return;
	}
	printf("Unesite vase ime i prezime.\n");
	printf("Ime: "); scanf("%s", administrator.ime);
	printf("Prezime: "); scanf("%s", administrator.prezime);
	printf("Vase korisnicko ime je: %s, a sifra: %s\n", korisnickoIme, sifra);
	printf("Unesite dato korisnicko ime i sifru.\n");
	printf("Korisnicko ime : ");
	scanf("%s", administrator.korisnickoIme);
	printf("Sifra: ");
	scanf("%s", administrator.sifra);

	while (strcmp(administrator.korisnickoIme, korisnickoIme) != 0 || strcmp(administrator.sifra, sifra) != 0) {
		printf("Neispravan unos podataka.\n");
		if (strcmp(administrator.korisnickoIme, korisnickoIme) != 0) {
			printf("Korisnicko ime : ");
			scanf("%s", administrator.korisnickoIme);
		}
		if (strcmp(administrator.sifra, sifra) != 0) {
			printf("Sifra: ");
			scanf("%s", administrator.sifra);
		}
	}

	printf("Unesite novu sifru. Sifra mora imati bar 8 znakova od kojih je jedan veliko slovo, a jedan broj.\n");
	printf("sifra: "); scanf("%s", administrator.sifra);

	while (istaSifra(administrator.sifra, sifra) || provjeraFormataSifre(administrator.sifra) == 0) {
		printf("sifra: "); scanf("%s", administrator.sifra);
	}

	administrator.brojPrijava = 1;
	if (f = fopen("PrviAdministrator.txt", "w")) {
		fprintf(f, "%s %s", administrator.korisnickoIme, administrator.sifra);
		fclose(f);
	}
	else {
		printf("Neuspjesno azuriranje podataka.\n");
		return;
	}
	if (f = fopen("Administratori.txt", "a")) {

		fprintf(f, "%s %s %s %s\n", administrator.ime, administrator.prezime, administrator.korisnickoIme, administrator.sifra);
		fclose(f);
	}
	else {
		printf("Neuspjesno otvaranje datoteke.\n");
		return;
	}
	if (f = fopen("Prijavljeni korisnici.txt", "a")) {
		fprintf(f, "%s %s %d %d\n", administrator.korisnickoIme, administrator.sifra, administrator.brojPrijava, 0);
		fclose(f);
	}
	else {
		printf("Neuspjesna prijava.\n");
		return;
	}
	printf("Prijava uspjesna.\n");
}

int istaSifra(char* sifra1, char* sifra2) {
	if (strcmp(sifra1, sifra2) == 0) {
		printf("Unijeli ste istu sifru.\n");
		return 1;
	}
	return 0;
}
