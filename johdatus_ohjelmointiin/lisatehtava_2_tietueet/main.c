#include <stdio.h>
#include <string.h>

typedef struct Kirja {
    char nimi[50];
    int lainassa;
    char lainaaja[30];
    int lainakerrat;
} Kirja;

void kirjan_tallennus(Kirja *kirja) {

    printf("\nAnna kirjan nimi: ");
    scanf("%s", kirja->nimi);

    strcpy(kirja->lainaaja, "");
    kirja->lainassa = 0;
    kirja->lainakerrat = 0;
}

void kirjojen_tulostus(Kirja *kirja, int next_index) {
    if (next_index == 0) { // oletetaan etta kirja taulukko on tyhja
        printf("\nEt ole viela lisannyt yhtaan kirjaa.");
        return;
    }

    for(int i = 0; i < next_index; i++) {
        printf("\n%d. Kirja: %s, ", i + 1, kirja[i].nimi);
        if (kirja[i].lainassa) {
            printf("Kirjan lainaaja: %s, ", kirja[i].lainaaja);
        }
        printf("Kertaa lainattu: %d", kirja[i].lainakerrat);
    }
}

void kirjan_lainaus(Kirja *kirja, int next_index) {
    if (next_index == 0) { // oletetaan etta kirja taulukko on tyhja
        printf("\nEt ole viela lisannyt yhtaan kirjaa.");
        return;
    }

    char lainatun_nimi[20];

    printf("\nKirja jota lainaat: ");
    scanf("%s", &lainatun_nimi);

    for(int i = 0; i < next_index; i++) {
        if (strcmp(kirja[i].nimi, lainatun_nimi) == 0 && kirja[i].lainassa == 0) {
            char lainaajan_nimi[20];

            printf("\nAnna nimesi: ");
            scanf("%s", lainaajan_nimi);

            strcpy(kirja[i].lainaaja, lainaajan_nimi);
            kirja[i].lainassa = 1;
            kirja[i].lainakerrat++;

            return;
        }
    }

    printf("\nKirjaa ei loytynyt.");
}

void kirjan_palautus(Kirja *kirja, int next_index) {
    if (next_index == 0) { // oletetaan etta kirja taulukko on tyhja
        printf("\nEt ole viela lisannyt yhtaan kirjaa.");
        return;
    }

    char palautetun_nimi[20];

    printf("\nKirja jota palautat: ");
    scanf("%s", &palautetun_nimi);

    for(int i = 0; i < next_index; i++) {
        if (strcmp(kirja[i].nimi, palautetun_nimi) == 0 && kirja[i].lainassa == 1) {
            strcpy(kirja[i].lainaaja, "");
            kirja[i].lainassa = 0;

            return;
        }
    }

    printf("\nKirjaa ei loytynyt.");
}

void lainattujen_kirjojen_tulostus(Kirja *kirja, int next_index) {
    if (next_index == 0) { // oletetaan etta kirja taulukko on tyhja
        printf("\nEt ole viela lisannyt yhtaan kirjaa.");
        return;
    }

    for(int i = 0; i < next_index; i++) {
        if (kirja[i].lainassa) {
            printf("\n%d. Kirja: %s, ", i + 1, kirja[i].nimi);
            printf("Kirjan lainaaja: %s, ", kirja[i].lainaaja);
            printf("Kertaa lainattu: %d", kirja[i].lainakerrat);
        }
    }
}

void nollaa_taulukko(int *taulukko, int koko) {
    for (int i = 0; i < koko; i++) {
        taulukko[i] = -1;
    }
}

void eniten_lainattujen_kirjojen_tulostus(Kirja *kirja, int next_index) {
    if (next_index == 0) { // oletetaan etta kirja taulukko on tyhja
        printf("\nEt ole viela lisannyt yhtaan kirjaa.");
        return;
    }

    int isoin_maara = 0;

    int indeksit[20];
    int kirjojen_maara = 0;
    nollaa_taulukko(indeksit, 20); // nollataan -1 luvulla

    for(int i = 0; i < next_index; i++) {
        if(kirja[i].lainakerrat > isoin_maara) {
            nollaa_taulukko(indeksit, 20); // nollataan -1 luvulla

            isoin_maara = kirja[i].lainakerrat;

            indeksit[0] = i;

            kirjojen_maara = 1;
        } else if (kirja[i].lainakerrat == isoin_maara){
            indeksit[kirjojen_maara] = i;
            kirjojen_maara++;
        }
    }

    for(int i = 0; i < kirjojen_maara; i++) {
        printf("\n%d. Kirja: %s, ", i + 1, kirja[indeksit[i]].nimi);
        if (kirja[indeksit[i]].lainassa) {
            printf("Kirjan lainaaja: %s, ", kirja[indeksit[i]].lainaaja);
        }
        printf("Kertaa lainattu: %d", kirja[indeksit[i]].lainakerrat);
    }
}

int main()
{
    int max_books = 20;
    Kirja kirjat[max_books];

    int next_index = 0;

    while(1) {
        printf("\n");
        printf("\n");
        printf("\n1. Lisaa kirja");
        printf("\n2. Tulosta kaikki kirjat");
        printf("\n3. Lainaa kirja");
        printf("\n4. Palauta kirja");
        printf("\n5. Tulosta vain lainatut kirjat");
        printf("\n6. Tulosta kirjat, joita on lainattu eniten");
        printf("\n7. Lopeta ohjelma");

        int menu_choice;
        printf("\n\nValinta: ");
        scanf("%d", &menu_choice);

        switch(menu_choice) {
            case 1: {
                if (next_index < max_books - 1) {
                    kirjan_tallennus(&kirjat[next_index]);
                    next_index++;
                } else {
                    printf("\nEi mahdu enempaa kirjoja. Kirjoja on: %d", next_index);
                }
                break;
            }
            case 2: {
                kirjojen_tulostus(kirjat, next_index);
                break;
            }
            case 3: {
                kirjan_lainaus(kirjat, next_index);
                break;
            }
            case 4: {
                kirjan_palautus(kirjat, next_index);
                break;
            }
            case 5: {
                lainattujen_kirjojen_tulostus(kirjat, next_index);
                break;
            }
            case 6: {
                eniten_lainattujen_kirjojen_tulostus(kirjat, next_index);
                break;
            }

            case 7: {
                printf("\n\nOhjelma sulkeutuu.");
                return 0;
            }
            default: {
                break;
            }
        }
    }

	printf("Hello World!\n");
	return 0;
}
