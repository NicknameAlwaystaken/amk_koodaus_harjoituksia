#include <stdio.h>
#include <string.h>

typedef struct Kirja {
    char nimi[50];
    int lainassa;
    char lainaaja[30];
    int lainakerrat;
} Kirja;

int kirjan_tallennus(Kirja *kirja, int seuraava_indeksi) {

    char uuden_kirjan_nimi[50];
    printf("\nAnna kirjan nimi: ");
    scanf("%s", uuden_kirjan_nimi);

    // käydään kirjat läpi
    for(int i = 0; i < seuraava_indeksi; i++) {
        // onko saman nimistä kirjaa olemassa
				if(strcmp(kirja[i].nimi, uuden_kirjan_nimi) == 0) {
            // ei haluta tallentaa kirjaa joka jakaa nimen toisen kanssa
            return 0; // palautetaan 0 että tiedetään ettei uutta kirjaa tallennettu
        }
    }

    strcpy(kirja->lainaaja, "");
    kirja->lainassa = 0;
    kirja->lainakerrat = 0;
    return 1; // uusi kirja lisättiin
}

void kirjojen_tulostus(Kirja *kirja, int seuraava_indeksi) {
    if (seuraava_indeksi == 0) { // oletetaan etta kirja taulukko on tyhja
        printf("\nEt ole viela lisannyt yhtaan kirjaa.");
        return;
    }

    // käydään kirjat läpi
    for(int i = 0; i < seuraava_indeksi; i++) {
        printf("\n%d. Kirja: %s, ", i + 1, kirja[i].nimi);
        if (kirja[i].lainassa) {
            printf("Kirjan lainaaja: %s, ", kirja[i].lainaaja);
        }
        printf("Kertaa lainattu: %d", kirja[i].lainakerrat);
    }
}

void kirjan_lainaus(Kirja *kirja, int seuraava_indeksi) {
    if (seuraava_indeksi == 0) { // oletetaan etta kirja taulukko on tyhja
        printf("\nEt ole viela lisannyt yhtaan kirjaa.");
        return;
    }

    char lainatun_nimi[20];

    printf("\nKirja jota lainaat: ");
    scanf("%s", lainatun_nimi);

    // käydään kirjat läpi
    for(int i = 0; i < seuraava_indeksi; i++) {
        // jos kirja löytyy ja ei ole lainassa niin lainataan
        if (strcmp(kirja[i].nimi, lainatun_nimi) == 0 && kirja[i].lainassa == 0) {
            char lainaajan_nimi[20];

            // kysytään lainaajan nimi
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

void kirjan_palautus(Kirja *kirja, int seuraava_indeksi) {
    if (seuraava_indeksi == 0) { // oletetaan etta kirja taulukko on tyhja
        printf("\nEt ole viela lisannyt yhtaan kirjaa.");
        return;
    }

    char palautetun_nimi[20];

    printf("\nKirja jota palautat: ");
    scanf("%s", palautetun_nimi);

    // käydään kirjat läpi
    for(int i = 0; i < seuraava_indeksi; i++) {
        // jos on lainassa niin palautetaan nollaamalla tiedot
        if (strcmp(kirja[i].nimi, palautetun_nimi) == 0 && kirja[i].lainassa == 1) {
            strcpy(kirja[i].lainaaja, "");
            kirja[i].lainassa = 0;

            return;
        }
    }

    printf("\nKirjaa ei loytynyt.");
}

void lainattujen_kirjojen_tulostus(Kirja *kirja, int seuraava_indeksi) {
    if (seuraava_indeksi == 0) { // oletetaan etta kirja taulukko on tyhja
        printf("\nEt ole viela lisannyt yhtaan kirjaa.");
        return;
    }

    // käydään kirjat läpi
    for(int i = 0; i < seuraava_indeksi; i++) {
        // jos on lainassa niin tulostetaan
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

void eniten_lainattujen_kirjojen_tulostus(Kirja *kirja, int seuraava_indeksi) {
    if (seuraava_indeksi == 0) { // oletetaan etta kirja taulukko on tyhja
        printf("\nEt ole viela lisannyt yhtaan kirjaa.");
        return;
    }

    int korkein_lainaus_maara = 0; // muistetaan korkein lainausmäärä

    int indeksit[20]; // muistetaan mitkä kirjat halutaan tulostaa
    // käyttäen niitten indeksiä
    int kirjojen_maara = 0; // tiedetään monta kirjaa halutaan tulostaa

    // käydään kirjat läpi
    for(int i = 0; i < seuraava_indeksi; i++) {
        if(kirja[i].lainakerrat > korkein_lainaus_maara) {
            // jos löytyi kirja jolla on vielä korkeampi lainausmäärä
            // niin tyhjennetään aikaisemmat kerätyt tiedot
            // ja aloitetaan alusta laskeminen
            korkein_lainaus_maara = kirja[i].lainakerrat;

            indeksit[0] = i;

            kirjojen_maara = 1;
        } else if (kirja[i].lainakerrat == korkein_lainaus_maara){
            // löytyi lisää kirjoja joka jakaa lainausmäärän korkeimman kanssa
            indeksit[kirjojen_maara] = i;
            kirjojen_maara++;
        }
    }

    // käydään läpi tallennettu lista korkeimmista laina määristä
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
    int max_kirjat = 20; // kuinka monta kirjaa halutaan tallentaa kerralla
    Kirja kirjat[max_kirjat]; // luodaan taulukko Kirja structista

    int seuraava_indeksi = 0; // seuraavan kirjan indeksin numero

    while(1) {
        int valikko_valinta;
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

            printf("\n\nValinta: ");
            if (scanf("%d", &valikko_valinta) == 1) {
                // syöte onnistui
                break;
            }

            printf("\nEt antanut oikean muotoista syotetta.");
            while(getchar() != '\n'); // tyhjennä syöte
        }

        switch(valikko_valinta) {
            case 1: {
                if (seuraava_indeksi < max_kirjat) {
                    // tarkistetaan onko tilaa uudelle kirjalle tallentaa
                    if (kirjan_tallennus(&kirjat[seuraava_indeksi], seuraava_indeksi)) {
                        seuraava_indeksi++;
                    }
                } else {
                    printf("\nEi mahdu enempaa kirjoja. Kirjoja on: %d", seuraava_indeksi);
                }
                break;
            }
            case 2: {
                kirjojen_tulostus(kirjat, seuraava_indeksi);
                break;
            }
            case 3: {
                kirjan_lainaus(kirjat, seuraava_indeksi);
                break;
            }
            case 4: {
                kirjan_palautus(kirjat, seuraava_indeksi);
                break;
            }
            case 5: {
                lainattujen_kirjojen_tulostus(kirjat, seuraava_indeksi);
                break;
            }
            case 6: {
                eniten_lainattujen_kirjojen_tulostus(kirjat, seuraava_indeksi);
                break;
            }

            case 7: {
                printf("\n\nOhjelma sulkeutuu.");
                return 0;
            }
            default: {
                // Poistutaan silmukasta joka johtaa ohjelman päättymiseen
                break;
            }
        }
    }

    printf("\n");
	return 0;
}
