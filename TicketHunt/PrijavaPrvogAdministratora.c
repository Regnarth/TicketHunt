#include "PrijavaPrvogAdministratora.h"
#include "KreiranjeNaloga.h"
#include "LoadConfig.h"

int prviAdministrator(USER* user) {

	char korisnickoIme[MAX] = "";
	char sifra[MAX] = "";
	char c = 0;
	FILE* f = 0;
	if (f = fopen(concat(CONFIG_DEV_FOLDER, "PrviAdministrator.txt"), "r")) {
		fscanf(f, "%s %s %c", korisnickoIme, sifra, &c);
		fclose(f);
	}
	else {
		printf("Neuspjesno otvaranje datoteke.\n");
		printf("Neuspjela prijava.\n");
		return 0;
	}
	printf("Unesite vase ime i prezime.\n");
	printf("Ime: "); scanf("%s", user->ime);
	printf("Prezime: "); scanf("%s", user->prezime);
	printf("Vase korisnicko ime je: %s, a sifra: %s\n", korisnickoIme, sifra);
	printf("Unesite dato korisnicko ime i sifru.\n");
	printf("Korisnicko ime : ");
	scanf("%s", user->username);
	printf("Sifra: ");
	scanf("%s", user->password);

	while (strcmp(user->username, korisnickoIme) != 0 || strcmp(user->password, sifra) != 0) {
		printf("Neispravan unos podataka.\n");
		if (strcmp(user->username, korisnickoIme) != 0) {
			printf("Korisnicko ime : ");
			scanf("%s", user->username);
		}
		if (strcmp(user->password, sifra) != 0) {
			printf("Sifra: ");
			scanf("%s", user->password);
		}
	}

	printf("Unesite novu sifru. Sifra mora imati bar 8 znakova od kojih je jedan veliko slovo, a jedan broj.\n");
	printf("sifra: "); scanf("%s", user->password);

	while (istaSifra(user->password, sifra) || provjeraFormataSifre(user->password) == 0) {
		printf("sifra: "); scanf("%s", user->password);
	}

	if (f = fopen(concat(CONFIG_DEV_FOLDER, "PrviAdministrator.txt"), "w")) {
		fprintf(f, "%s %s %c", user->username, user->password, '-');
		fclose(f);
	}
	else {
		printf("Neuspjesno azuriranje podataka.\n");
		return 0;
	}
	if (f = fopen(concat(CONFIG_DEV_FOLDER, "Administratori.txt"), "a")) {

		fprintf(f, "%s %s %s %s\n", user->ime, user->prezime, user->username, user->password);
		fclose(f);
	}
	else {
		printf("Neuspjesno otvaranje datoteke.\n");
		return 0;
	}
	if (f = fopen(concat(CONFIG_DEV_FOLDER, "Prijavljeni korisnici.txt"), "a")) {
		fprintf(f, "%s %s %d %d\n", user->username, user->password, 1, 0);
		fclose(f);
	}
	else {
		printf("Neuspjesna prijava.\n");
		return 0;
	}
	printf("Prijava uspjesna.\n");
	return 1;
}

int istaSifra(char* sifra1, char* sifra2) {
	if (strcmp(sifra1, sifra2) == 0) {
		printf("Unijeli ste istu sifru.\n");
		return 1;
	}
	return 0;
}