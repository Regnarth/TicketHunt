#pragma once
#include "SuspendovanjeNaloga.h"

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

	if (memorisiNalog(f, korisnickoIme))
		printf("Nalog je uspjesno suspendovan.\n");

}

int provjeraSuspenzije(FILE* f, char* korisnickoIme) {

	if (f = fopen("Suspendovani.txt", "r")) {
		char pom[MAX];
		while (fscanf(f, "%s", pom) == 1) {
			if (strcmp(korisnickoIme, pom) == 0) {
				fclose(f);
				return 1;
			}
		}
	}

	return 0;

}

int memorisiNalog(FILE* f, char* korisnickoIme) {

	if (f = fopen("Suspendovani.txt", "a")) {

		fprintf(f, "%s\n", korisnickoIme);
		fclose(f);
		return 1;
	}
	else {
		printf("Neuspjesno otvaranje datoteke.\n");
		return 0;
	}
}
