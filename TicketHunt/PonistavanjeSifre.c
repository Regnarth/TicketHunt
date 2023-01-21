#include "PonistavanjeSifre.h"
#include "LoadConfig.h"
void ponistiSifru() {

	char korisnickoIme[MAX];
	printf("Unesite korisnicko ime naloga kome zelite ponistiti sifru.\n");
	scanf("%s", korisnickoIme);
	FILE* f = 0;
	if (!provjeraPostojanja(f, korisnickoIme)) {
		printf("Nalog ne postoji.\n");
	}

	if (memorisiSifru(f, korisnickoIme))
		printf("Sifra je uspjesno ponistena.\n");

}

int provjeraPostojanja(FILE* f, char* korisnickoIme) {

	if (f = fopen(concat(CONFIG_DEV_FOLDER,"Klijenti.txt"), "r")) {
		char pom1[MAX];
		while (fscanf(f, "%s", pom1) == 1) {
			if (strcmp(korisnickoIme, pom1) == 0) {
				fclose(f);
				return 1;
			}
		}
		fclose(f);
	}
	if (f = fopen(concat(CONFIG_DEV_FOLDER,"Korisnici.txt"), "r")) {
		char pom2[MAX];
		while (fscanf(f, "%s", pom2) == 1) {
			if (strcmp(korisnickoIme, pom2) == 0) {
				fclose(f);
				return 1;
			}
		}
		fclose(f);
	}
	return 0;

}

int memorisiSifru(FILE* f, char* korisnickoIme) {

	if (f = fopen(concat(CONFIG_DEV_FOLDER,"PonisteneSifre.txt"), "a")) {

		fprintf(f, "%s\n", korisnickoIme);
		fclose(f);
		return 1;
	}
	else {
		printf("Neuspjesno otvaranje datoteke.\n");
		return 0;
	}
}
