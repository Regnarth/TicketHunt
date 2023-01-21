#pragma once
#include "SuspendovanjeNaloga.h"
#include"AktivacijaNaloga.h"
#include "LoadConfig.h"

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

	if (f = fopen(concat(CONFIG_DEV_FOLDER, "Suspendovani.txt"), "r")) {
		char pom[MAX];
		while (fscanf(f, "%s", pom) == 1) {
			if (strcmp(korisnickoIme, pom) != 0)
				dodaj(&nalog, pom);
		}
		fclose(f);
	}
	else {
		printf("Neuspjesna aktivacija.\n");
		return;
	}
	invertuj(&nalog);
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

	if (f = fopen(concat(CONFIG_DEV_FOLDER, "Suspendovani.txt"), "w")) {
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

	while (*nalog) {
		NALOG* pom = *nalog;
		*nalog = pom->next;
		free(pom);
	}
}

void invertuj(NALOG** glava) {
	NALOG* p1 = *glava, * p2 = 0, * p3;
	while (p1) {
		p3 = p1->next;
		p1->next = p2;
		p2 = p1;
		p1 = p3;
	}
	*glava = p2;
}