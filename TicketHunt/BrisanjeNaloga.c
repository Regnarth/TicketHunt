#include "BrisanjeNaloga.h"
#include "Registracija.h"
#include "LoadConfig.h"
void obrisiNalog() {

	char korisnickoIme[MAX];
	printf("Unesite korisnicko ime naloga koji zelite da obrisete.\n");
	scanf("%s", korisnickoIme);

	if (!provjeriUsername(korisnickoIme))
	{
		printf("Nalog ne postoji.\n");
		return;
	}

	ACCOUNT* acc = 0;
	FILE* f;

	if (f = fopen(concat(CONFIG_DEV_FOLDER,"Korisnici.txt"), "r"))
	{
		USER pom;
		while (fscanf(f, "%s %s %s %s", pom.ime, pom.prezime, pom.username, pom.password) != EOF)
		{
			if (strcmp(korisnickoIme, pom.username) != 0)
				dodajNalog(&acc, &pom);
		}
		fclose(f);
	}

	invertujNaloge(&acc);

	if (ukloniNaloge(f, acc))
	{
		printf("Nalog je uspjesno obrisan.\n");
	}

	brisiNalog(&acc);
}

void dodajNalog(ACCOUNT** acc, USER* pom) {

	ACCOUNT* novi = (ACCOUNT*)malloc(sizeof(ACCOUNT));

	if (!novi) return;

	strcpy(novi->user.ime, pom->ime);
	strcpy(novi->user.prezime, pom->prezime);
	strcpy(novi->user.username, pom->username);
	strcpy(novi->user.password, pom->password);

	novi->next = *acc;
	*acc = novi;
}

void invertujNaloge(ACCOUNT** glava) {
	ACCOUNT* p1 = *glava, * p2 = 0, * p3;
	while (p1)
	{
		p3 = p1->next;
		p1->next = p2;
		p2 = p1;
		p1 = p3;
	}
	*glava = p2;
}

int ukloniNaloge(FILE* f, ACCOUNT* nalog) {

	if (f = fopen(concat(CONFIG_DEV_FOLDER,"Korisnici.txt"), "w")) {
		while (nalog)
		{
			fprintf(f, "%s %s %s %s\n", nalog->user.ime, nalog->user.prezime, nalog->user.username, nalog->user.password);
			nalog = nalog->next;
		}
		fclose(f);
		return 1;
	}
	else
	{
		printf("Neuspjesno otvaranje datoteke.\n");
		return 0;
	}
}
void brisiNalog(ACCOUNT** nalog) {

	while (*nalog)
	{
		ACCOUNT* pom = *nalog;
		*nalog = pom->next;
		free(pom);
	}
}