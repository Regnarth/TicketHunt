#pragma once
#include "SuspendovanjeNaloga.h"
#include"AktivacijaNaloga.h"

void aktivirajNalog() {

	char korisnickoIme[MAX];
	printf("Unesite korisnicko ime naloga koji zelite da aktivirate.\n");
	scanf("%s", korisnickoIme);

	FILE* f = 0;

	if (!provjeraSuspenzije(f, korisnickoIme)) {
		printf("Nalog nije suspendovan.\n");
		return;
	}

	NALOG* nalog = 0;

	if (f = fopen("Suspendovani.txt", "r")) {
		char pom[MAX];
		while (fscanf(f, "%s", pom) == 1) {
			if (strcmp(korisnickoIme, pom) != 0)
				dodaj(&nalog, pom);
		}
		fclose(f);
	}

	if (ukloniNalog(f, nalog))
		printf("Nalog je uspjesno aktiviran.\n");

	brisi(&nalog);
}

void dodaj(NALOG** nalog, char* korisnickoIme) {

	NALOG* novi = (NALOG*)malloc(sizeof(NALOG));

	if (!novi) return;

	strcpy(novi->korisnickoIme, korisnickoIme);

	novi->next = *nalog;
	*nalog = novi;
}

int ukloniNalog(FILE* f, NALOG* nalog) {

	if (f = fopen("Suspendovani.txt", "w")) {
		while (nalog) {
			fprintf(f, "%s\n", nalog->korisnickoIme);
			nalog = nalog->next;
		}
		fclose(f);
		return 1;
	}
	else {
		printf("Neuspjesno otvaranje datoteke.\n");
		return 0;
	}
}

void brisi(NALOG** nalog) {

	while(*nalog){
	NALOG* pom = *nalog;
	*nalog = pom->next;
	free(pom);
	}
}