#include <stdio.h>
#include <stdlib.h>

void tulosta() {
	printf("Hei maailma!\n");
}

void task_1() {
/*
    1. Tee ohjelma, jossa on pääohjelma (main-funktio) ja aliohjelma (funktio) nimeltä tulosta().
    Pääohjelmasta kutsutaan em. aliohjelmaa, joka tulostaa näytölle ”Hei maailma!”.
*/

    tulosta();
}

int lue() {
    int kokonaisluku;
    printf("\nAnna kokonaisluku: ");
    scanf("%d", &kokonaisluku);

    return kokonaisluku;
}

void task_2() {
/*
    2. Tee ohjelma, jossa on pääohjelma (main-funktio) ja aliohjelma (funktio) nimeltä lue().
    Pääohjelmasta kutsutaan em. aliohjelmaa, joka tulostaa näytölle ”Anna kokonaisluku”.
    Tässä aliohjelmassa luetaan myös kokonaisluku ja palautetaan se pääohjelmaan, joka
    tulostaa luvun näytölle.
*/

    int uusi_kokonaisluku = lue();

    printf("\nLuettu luku: %d\n", uusi_kokonaisluku);
}

void luvunTulostus(int kokonaisluku) {
    printf("\nLuettu luku: %d\n", kokonaisluku);
}

void task_3() {
/*
    3. Muuta edellistä ohjelmaa siten, että lisäät siihen luvunTulostus() nimisen aliohjelman. Tätä
    aliohjelmaa kutsutaan pääohjelmasta (sitten, kun luku on luettu) ja siihen välitetään luettu
    kokonaisluku. luvunTulostus() aliohjelma tulostaa siihen välitetyn luvun näytölle.
*/
    int kokonaisluku;
    printf("\nAnna kokonaisluku: ");
    scanf("%d", &kokonaisluku);

    luvunTulostus(kokonaisluku);
}

float kerrotaan_kolmella(float annettu_luku) {
    float tulos = annettu_luku * 3.0;
    return tulos;
}

void task_4() {
/*
    4. Tee ohjelma jossa on pääohjelma (main-funktio) sekä yksi funktio eli aliohjelma, joka kysyy
    float-luvun käyttäjältä, kertoo luvun kolmella ja palauttaa tuloksen main()-funktiolle, jossa
    tulos tulostetaan näytölle.
*/
    float float_luku;
    printf("\nAnna float luku: ");
    scanf("%f", &float_luku);

    float uusi_luku = kerrotaan_kolmella(float_luku);

    printf("\nLuettu luku: %f\n", uusi_luku);
}

void vertaile(int taulukko[], int numero1, int numero2) {
    if (numero1 > numero2) {
        taulukko[0] = numero1;
        taulukko[1] = numero2;
    } else {
        taulukko[0] = numero2;
        taulukko[1] = numero1;
    }
}

void task_5 () {
/*
    5. Tee ohjelma, jossa on funktio vertaile() johon viedään kaksi kokonaislukua. Tämä funktio
    vertailee niiden suuruutta ja tulostaa ne suuruusjärjestyksessä näytölle (suurin ensin).
*/
    int numero1, numero2, taulukko[2];

    printf("\nAnna eka numero: ");
    scanf("%d", &numero1);

    printf("\nAnna toka numero: ");
    scanf("%d", &numero2);

    vertaile(taulukko, numero1, numero2);

    if (taulukko[0] > taulukko[1]) {
        printf("\n%d on isompi kuin %d\n", taulukko[0], taulukko[1]);
    } else {
        printf("\n%d ja %d ovat yhtasuuria\n", taulukko[0], taulukko[1]);
    }
}

float nelioLasku(float sivunpituus) {
    return sivunpituus * 4;
}

float ympyraLasku(float sateenpituus) {
    return sateenpituus * 2 * 3.14;
}


void task_6() {
/*
    6. Tee ohjelma joka tulostaa käyttäjälle seuraavan valikon, jossa on kolme vaihtoehtoa:
    1. Neliön kehän pituus
    2. Ympyrän kehän pituus
    9. Lopetus.
    Käyttäjä voi valita halutun toiminnan syöttämällä 1,2 tai 9.
    Valinta 1 saa aikaan nelioLasku()- funktion kutsun, valinta 2 saa aikaan ympyraLasku()-
    funktion kutsun. Em. funktioissa lasketaan ja tulostetaan neliön ja ympyrän kehän pituudet.
    Ympyrän kehä lasketaan kaavalla 2*3.14*ympyränSäde. Neliön kehä lasketaan kaavalla
    kehänPituus=4*sivunPituus. Muista kysyä funktioissa käyttäjältä tarvittaessa ympyrän säde
    ja neliön sivun pituus. Aina kehänpituuden laskennan ja tulostuksen jälkeen valikko
    tulostetaan näytölle uudelleen. Valinta 9 lopettaa ohjelman. (Käytä while-toistorakennetta)
*/
    int task_number;

    while(1) {
        printf("\n1. Nelion kehan pituus");
        printf("\n2. Ympyran kehan pituus");
        printf("\n9. Lopetus");
        printf("\nValinta: ");
        scanf("%d", &task_number);
        switch (task_number) {
            case 1: {
                float sivunpituus;

                printf("\nValittu nelion kehan pituus");

                printf("\nSivun pituus: ");
                scanf("%f", &sivunpituus);

                float nelion_tulos = nelioLasku(sivunpituus);

                printf("Nelion tulos: %.2f", nelion_tulos);
                break;
            }
            case 2: {
                float sateenpituus;
                printf("\nValittu ympyran kehan pituus");

                printf("\nSateen pituus: ");
                scanf("%f", &sateenpituus);

                float ympyran_tulos = ympyraLasku(sateenpituus);

                printf("Ympyran tulos: %.2f", ympyran_tulos);
                break;
            }
            case 9: {
                return;
            }
        }
    }
}

void tulostaMerkkijono (char teksti[]) {
    printf("\n%s\n", teksti);
}

void task_7 () {
/*
    7. Tee ohjelma, jossa välität funktioon merkkijonon (merkkitaulukon), joka on määritelty
    paikalliseksi (ei globaali) muuttujaksi. Funktiossa tämä merkkijono tulostetaan näytölle.
*/
    char teksti[] = "Jotain hauskaa tekstia.";

    tulostaMerkkijono(teksti);
}

void task_8 () {
/*
    8. Tee ohjelma, joka lukee käyttäjän syöttämän kokonaisluvun (int) ja desimaaliluvun (double)
    char-taulukkoon. Sitten ohjelma summaa luvut ja tulostaa näyttöön. (Käytä <stdlib.h>
    kirjaston atoi()- ja atof()-funktioita, jotka muuttavat merkkijonon luvuksi
    int luku=atoi(merkkijono); //muuntaa merkkijonon kokonaisluvuksi
    double luku2=atof(merkkijono); //muuntaa merkkijonon double luvuksi)
*/
    char merkkijono[2][30];

    printf("\nKokonaisluku: ");
    scanf("%s", merkkijono[0]);

    printf("\nDesimaaliluku: ");
    scanf("%s", merkkijono[1]);

    int kokonaisluku = atoi(merkkijono[0]);
    double desimaaliluku = atof(merkkijono[1]);

    printf("%d + %lf = %lf", kokonaisluku, desimaaliluku, kokonaisluku + desimaaliluku);
}

int main()
{
	int task_number;
    while(1) {
        printf("\n\nGive task number or give 0 to exit program.\n");
        printf("\nFunktiot eli aliohjelmat");
        printf("\n1. Tee ohjelma, jossa on pääohjelma (main-funktio) ja aliohjelma (funktio) nimeltä tulosta().\nPääohjelmasta kutsutaan em. aliohjelmaa, joka tulostaa näytölle ”Hei maailma!”.");
        printf("\n");
        printf("\n2. Tee ohjelma, jossa on pääohjelma (main-funktio) ja aliohjelma (funktio) nimeltä lue().");
        printf("\nPääohjelmasta kutsutaan em. aliohjelmaa, joka tulostaa näytölle ”Anna kokonaisluku”.");
        printf("\nTässä aliohjelmassa luetaan myös kokonaisluku ja palautetaan se pääohjelmaan, joka");
        printf("\ntulostaa luvun näytölle.");
        printf("\n");
        printf("\n3. Muuta edellistä ohjelmaa siten, että lisäät siihen luvunTulostus() nimisen aliohjelman. Tätä");
        printf("\naliohjelmaa kutsutaan pääohjelmasta (sitten, kun luku on luettu) ja siihen välitetään luettu");
        printf("\nkokonaisluku. luvunTulostus() aliohjelma tulostaa siihen välitetyn luvun näytölle.");
        printf("\n");
        printf("\n4. Tee ohjelma jossa on pääohjelma (main-funktio) sekä yksi funktio eli aliohjelma, joka kysyy");
        printf("\nfloat-luvun käyttäjältä, kertoo luvun kolmella ja palauttaa tuloksen main()-funktiolle, jossa");
        printf("\ntulos tulostetaan näytölle.");
        printf("\n");
        printf("\n5. Tee ohjelma, jossa on funktio vertaile() johon viedään kaksi kokonaislukua. Tämä funktio");
        printf("\nvertailee niiden suuruutta ja tulostaa ne suuruusjärjestyksessä näytölle (suurin ensin).");
        printf("\n");
        printf("\n6. Tee ohjelma joka tulostaa käyttäjälle seuraavan valikon, jossa on kolme vaihtoehtoa:");
        printf("\n1. Neliön kehän pituus");
        printf("\n2. Ympyrän kehän pituus");
        printf("\n9. Lopetus.");
        printf("\nKäyttäjä voi valita halutun toiminnan syöttämällä 1,2 tai 9.");
        printf("\nValinta 1 saa aikaan nelioLasku()- funktion kutsun, valinta 2 saa aikaan ympyraLasku()-");
        printf("\nfunktion kutsun. Em. funktioissa lasketaan ja tulostetaan neliön ja ympyrän kehän pituudet.");
        printf("\nYmpyrän kehä lasketaan kaavalla 2*3.14*ympyränSäde. Neliön kehä lasketaan kaavalla");
        printf("\nkehänPituus=4*sivunPituus. Muista kysyä funktioissa käyttäjältä tarvittaessa ympyrän säde");
        printf("\nja neliön sivun pituus. Aina kehänpituuden laskennan ja tulostuksen jälkeen valikko");
        printf("\ntulostetaan näytölle uudelleen. Valinta 9 lopettaa ohjelman. (Käytä while-toistorakennetta)");
        printf("\n");
        printf("\n7. Tee ohjelma, jossa välität funktioon merkkijonon (merkkitaulukon), joka on määritelty");
        printf("\npaikalliseksi (ei globaali) muuttujaksi. Funktiossa tämä merkkijono tulostetaan näytölle.");
        printf("\n");
        printf("\n8. Tee ohjelma, joka lukee käyttäjän syöttämän kokonaisluvun (int) ja desimaaliluvun (double)");
        printf("\nchar-taulukkoon. Sitten ohjelma summaa luvut ja tulostaa näyttöön. (Käytä <stdlib.h>");
        printf("\nkirjaston atoi()- ja atof()-funktioita, jotka muuttavat merkkijonon luvuksi");
        printf("\nint luku=atoi(merkkijono); //muuntaa merkkijonon kokonaisluvuksi");
        printf("\ndouble luku2=atof(merkkijono); //muuntaa merkkijonon double luvuksi)");

        printf("\n\nInput: ");
        scanf("%d", &task_number);
        switch (task_number) {
            case 1: {
                printf("\nTask number: %d\n", task_number);
                task_1();
                break;
            }
            case 2: {
                printf("\nTask number: %d\n", task_number);
                task_2();
                break;
            }
            case 3: {
                printf("\nTask number: %d\n", task_number);
                task_3();
                break;
            }
            case 4: {
                printf("\nTask number: %d\n", task_number);
                task_4();
                break;
            }
            case 5: {
                printf("\nTask number: %d\n", task_number);
                task_5();
                break;
            }
            case 6: {
                printf("\nTask number: %d\n", task_number);
                task_6();
                break;
            }
            case 7: {
                printf("\nTask number: %d\n", task_number);
                task_7();
                break;
            }
            case 8: {
                printf("\nTask number: %d\n", task_number);
                task_8();
                break;
            }
        }
        if (task_number == 0) {
            printf("\nExiting program...\n");
            break;
        }
    }
    return 0;
}
