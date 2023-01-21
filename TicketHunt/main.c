//#include <stdio.h>
#include <stdlib.h>
#include "Registracija.h"
#include "KreiranjeNaloga.h"
#include "PrijavaNaSistem.h"
#include "PregledNaloga.h"
#include "AktivacijaNaloga.h"
#include "BrisanjeNaloga.h"
#include "SuspendovanjeNaloga.h"
#include "AktivacijaNaloga.h"
#include "PonistavanjeSifre.h"
#include "PromjenaSifre.h"
#include "PregledListeDogadjaja.h"
#include "BrisanjeDogadjaja.h"
#include "KupovinaUlaznice.h"
#include "PonistavanjeUlaznice.h"
#include "OtkazivanjeKupljeneUlaznice.h"
#include "OdjavaSaSistema.h"
#include "AktivacijaDogadjaja.h"
#include "BlokiranjeDogadjaja.h"
#include "KreiranjeIzvjestaja.h"
#include "PregledDogadjaja.h"
#include "PregledUlaznica.h"
#include "PrijavaPrvogAdministratora.h"
#include "OdjavaSaSistema.h"
#include "LoadConfig.h"

int main()
{
	loadConfig();

	struct User user; user.kredit = 100;
	int pom;
	do {
		printf("Registracija:1\n");
		printf("Prijava:2\n");
		scanf("%d", &pom);
		if (pom == 1)register_user();
	} while (pom != 2);
	if (prijavaNaSistem(&user)) {
		if (user.vrstaNaloga == 1) {
			do {
				printf("Kreiranje naloga:1\n");
				printf("Pregled liste kreiranih naloga:2\n");
				printf("Aktivacija naloga:3\n");
				printf("Suspendovanje naloga:4\n");
				printf("Brisanje naloga:5\n");
				printf("Ponistavanje sifre:6\n");
				printf("Blokiranje dogadjaja:7\n");
				printf("Aktivacija dogadjaja:8\n");
				printf("Kreiranje izvjestaja o prodaji:9\n");
				printf("Promjena sifre:10\n");
				printf("Odjava sa sistema:11\n");
				scanf("%d", &pom);
				switch (pom) {
				case 1:
					kreirajNalog();
					break;
				case 2:
					pregledNaloga();
					break;
				case 3:
					aktivirajNalog();
					break;
				case 4:
					suspendujNalog();
					break;
				case 5:
					obrisiNalog();
					break;
				case 6:
					ponistiSifru();
					break;
				case 7:
					blokirajDogadjaj();
					break;
				case 8:
					aktivirajDogadjaj();
					break;
				case 9:
					KreiranjeIzvjestaja();
					break;
				case 10:
					mijenjajSifru(&user);
					break;
				case 11:
					odjavaSaSistema(user.username);
					break;
				default:
					break;

				}
			} while (pom != 11);

		}
		else if (user.vrstaNaloga == 2) {
			do {
				printf("Kreiranje dogadjaja:1\n");
				printf("Brisanje dogadjaja:2\n");
				printf("Pregled liste prodatih ulaznica:3\n");
				printf("Ponistavanje ulaznice:4\n");
				printf("Pregled liste dogadjaja:5\n");
				printf("Promjena sifre:6\n");
				printf("Odjava sa sistema:7\n");
				scanf("%d", &pom);
				switch (pom) {
				case 1:
					unosDogadjaja();
					break;
				case 2:
					brisanjeDogadjaja();
					break;
				case 3:
					pregled_prodatih_ulaznica();
					break;
				case 4:
					ponistavanjeUlaznice();
					break;
				case 5:
					pregledListeDogadjaja("Dogadjaji.txt");
					break;
				case 6:
					mijenjajSifru(&user);
					break;
				case 7:
					odjavaSaSistema(user.username);
					break;
				default:
					break;

				}
			} while (pom != 7);

		}
		else if (user.vrstaNaloga == 3) {
			do {
				printf("Citanje opisa i informacija dogadjaja:1\n");
				printf("Kupovina ulaznice:2\n");
				printf("Otkazivanje kupljene ulaznice:3\n");
				printf("Promjena sifre:4\n");
				printf("Odjava sa sistema:5\n");
				scanf("%d", &pom);
				switch (pom) {
				case 1:
					PregledDogadjaja();
					break;
				case 2:
					KupovinaUlaznice(&user);
					break;
				case 3:
					otkazivanjeKupljeneUlaznice(user.username);
					break;
				case 4:
					mijenjajSifru(&user);
					break;
				case 5:
					odjavaSaSistema(user.username);
					break;
				default:
					break;

				}
			} while (pom != 5);

		}
	}
	return 0;
}

