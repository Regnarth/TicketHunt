#pragma once
#include "SuspendovanjeNaloga.h"
#include "KreiranjeNaloga.h"
#include "Registracija.h"
#include "LoadConfig.h"
void suspendujNalog() {

	char korisnickoIme[MAX];
	printf("Unesite korisnicko ime naloga koji zelite da suspendujete.\n");
	scanf("%s", korisnickoIme);
	FILE* f = 0;
	while (provjeraSuspenzije(f, korisnickoIme)) {
		printf("Nalog je vec suspendovan.\n");
		printf("Izaberite drugi nalog.\n");
		scanf("%s", korisnickoIme);
	}

	if (!traziKlijenta(f, korisnickoIme) && !provjeriUsernameKorisnika(korisnickoIme)) {
		printf("Neuspjesno suspendovanje. Dozvoljeno suspendovanje samo korisnickih i klijenskih naloga.\n");
		return;
	}

	if (memorisiNalog(f, korisnickoIme))
		printf("Nalog je uspjesno suspendovan.\n");

}

int provjeraSuspenzije(FILE* f, char* korisnickoIme) {

	if (f = fopen(concat(CONFIG_DEV_FOLDER,"Suspendovani.txt"), "r")) {
		char pom[MAX];
		while (fscanf(f, "%s", pom) == 1) {
			if (strcmp(korisnickoIme, pom) == 0) {
				fclose(f);
				return 1;
			}
		}
		fclose(f);
	}

	return 0;

}

int memorisiNalog(FILE* f, char* korisnickoIme) {

	if (f = fopen(concat(CONFIG_DEV_FOLDER,"Suspendovani.txt"), "a")) {

		fprintf(f, "%s\n", korisnickoIme);
		fclose(f);
		return 1;
	}
	else {
		printf("Neuspjesno otvaranje datoteke.\n");
		return 0;
	}
}
int provjeriUsernameKorisnika(char* username)
{
	int size = 1;
	USER pom;
	FILE* fp;
	int i = 0;
	if (fp = fopen(concat(CONFIG_DEV_FOLDER,"Korisnici.txt"), "r"))
	{
		while (fscanf(fp, "%s %s %s %s", pom.ime, pom.prezime, pom.username, pom.password) != EOF)
		{
			if (strcmp(username, pom.username) == 0) {
				fclose(fp);
				return 1;
			}
		}
		fclose(fp);
	}
	return 0;
}