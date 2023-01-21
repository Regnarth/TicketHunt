#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "OtkazivanjeKupljeneUlaznice.h"
#include "KupovinaUlaznice.h"
#include "LoadConfig.h"
void otkazivanjeKupljeneUlaznice(char* korisnickoIme)
{
	FILE* f;
	char sifra_ulaznice[255];
	int broj_linije = 0;
	int ukupan_broj_linija = 0;
	printf("Unesite sifru ulaznice koju zelite da otkazete: ");
	scanf("%s", sifra_ulaznice);
	int sifra_validna = 0;
	if (f = fopen(concat(CONFIG_DEV_FOLDER,"SifraKorisnicko.txt"), "r"))
	{

		int lineLength = 255;
		char line[255];
		while (fgets(line, lineLength, f))
		{
			ukupan_broj_linija++;
			char* pch;
			pch = strtok(line, " ");
			char* sifra = pch;
			if (strcmp(sifra, sifra_ulaznice) == 0)
			{
				pch = strtok(NULL, " ");
				char* username = pch;
				if (strcmp(username, korisnickoIme) == 0)
				{
					sifra_validna = 1;
					broj_linije = ukupan_broj_linija;
				}
			}
		}
		fclose(f);
		if (sifra_validna == 0)
		{
			printf("Niste kupili ulaznicu sa datom sifrom!");
		}
		else if (sifra_validna == 1) {
			obrisiLiniju(broj_linije);
			brisanjeLinije_drugifajl(broj_linije);
			printf("Ulaznica je uspjesno otkazana.");
		}
	}
	else {
		printf("Greska prilikom otvaranja fajla!");
	}
}

void obrisiLiniju(int broj_linije) {
	int line_number = 0;
	FILE* fptr1 = 0;
	FILE* fptr2 = 0;
	if (fptr1 = fopen(concat(CONFIG_DEV_FOLDER,"SifraKorisnicko.txt"), "r")) {
		if (fptr2 = fopen(concat(CONFIG_DEV_FOLDER,"replica.txt"), "w")) {
			char curr = getc(fptr1);
			if (curr != EOF) { line_number = 1; }
			while (1)
			{
				if (broj_linije != line_number)
					putc(curr, fptr2);
				curr = getc(fptr1);
				if (curr == '\n') line_number++;
				if (curr == EOF) break;
			}
			fclose(fptr2);
		}
		fclose(fptr1);
	}


	const char* filename = "SifraKorisnicko.txt";
	const char* pomocnifajl = "pomocni.txt";
	rename(concat(CONFIG_DEV_FOLDER, filename), concat(CONFIG_DEV_FOLDER, pomocnifajl));
	remove(concat(CONFIG_DEV_FOLDER, filename));
	rename(concat(CONFIG_DEV_FOLDER, "replica.txt"), concat(CONFIG_DEV_FOLDER, filename));
	remove(concat(CONFIG_DEV_FOLDER, pomocnifajl));
}

void brisanjeLinije_drugifajl(int broj_linije)
{
	int line_number = 0;
	FILE* fptr1 = fopen(concat(CONFIG_DEV_FOLDER,"Ulaznice.txt"), "r");
	FILE* fptr2 = fopen(concat(CONFIG_DEV_FOLDER,"replica.txt"), "w");
	char curr = getc(fptr1);
	if (curr != EOF) { line_number = 1; }
	while (1)
	{
		if (broj_linije != line_number)
			putc(curr, fptr2);
		curr = getc(fptr1);
		if (curr == '\n') line_number++;
		if (curr == EOF) break;
	}
	fclose(fptr1);
	fclose(fptr2);
	const char* filename = "Ulaznice.txt";
	const char* pomocnifajl = "pomocni.txt";
	rename(concat(CONFIG_DEV_FOLDER, filename), concat(CONFIG_DEV_FOLDER, pomocnifajl));
	remove(concat(CONFIG_DEV_FOLDER, filename));
	rename(concat(CONFIG_DEV_FOLDER, "replica.txt"), concat(CONFIG_DEV_FOLDER, filename));
	remove(concat(CONFIG_DEV_FOLDER, pomocnifajl));
}