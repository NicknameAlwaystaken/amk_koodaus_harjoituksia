#include <stdio.h>
#include <string.h>

struct Car {
    char brand[20];
    char model[50];
    int yearModel;
};

void populate_car(struct Car *car_1) {

    printf("\n");
    printf("Mika brandi: ");
    scanf("%s", car_1->brand);

    printf("Mika malli: ");
    scanf("%s", car_1->model);

    printf("Mika vuosimalli: ");
    scanf("%d", &car_1->yearModel);

    printf("\n");
}

void print_car(struct Car *car_1) {
    printf("\n");
    printf("\nBrandi: %s", car_1->brand);
    printf("\nMalli: %s", car_1->model);
    printf("\nVuosimalli: %d", car_1->yearModel);
}

void task_1() {
/*
    1. Kirjoita ohjelma, -jossa on tietue nimeltään Car, jossa seuraavat kentät:
    • brand CHAR(20)
    • model CHAR(50)
    • yearModel INT
    -luo Car-tyyppinen muuttuja nimeltään car_1
    -lisää koodi, jossa käyttäjältä kysytään car_1:n tiedot
    -lisää koodi, jolla tulostetaan car_1:n tiedot
*/

    struct Car car_1;

    populate_car(&car_1);

    print_car(&car_1);
}

void task_2() {
/*
    2. Kirjoita ohjelma, jossa on samanlainen tietue Car kuin edellä.
    Luo Car-tyyppinen taulukko, johon voidaan tallentaa 3 alkiota.
    Lisää koodi, jolla käyttäjältä kysellään kolmen auton tiedot ja ne tallennetaan em. taulukkoon.
    Lisää koodi, jolla em. autojen tiedot tulostetaan ruudulle.
*/
    int car_amount = 3;
    struct Car car_array[car_amount];

    for (int i = 0; i < car_amount; i++) {
        populate_car(&car_array[i]);
    }

    for (int i = 0; i < car_amount; i++) {
        print_car(&car_array[i]);
    }
}

void task_3() {
/*
    3. Kirjoita ohjelma, joka toimii kuten edellinen sovellus, mutta
    nyt kysytään viiden auton tiedot
    autojen tietoja ei tulosteta ruudulle
    kun autojen tiedot on annettu käyttäjältä kysytään auton merkki(brand) ja tulostetaan kaikki
    kyseisen merkin autojen tiedot. Käyttäjältä kysellään merkkiä, kunnes hän antaa merkiksi
    ”LOPETA”.
*/

    int car_amount = 5;
    struct Car car_array[car_amount];

    for (int i = 0; i < car_amount; i++) {
        populate_car(&car_array[i]);
    }

    char brand_input[20];

    while(1) {
        printf("\n\nKysy brandista tai kirjoita LOPETA: ");
        scanf("%s", brand_input);

        for (int i = 0; i < car_amount; i++) {
            if (strstr(car_array[i].brand, brand_input)) {
                print_car(&car_array[i]);
            }
        }
        if (strstr(brand_input, "LOPETA")) {
            printf("\nExiting program...\n");
            break;
        }
    }
}

int main()
{
	int task_number;
    while(1) {
        printf("\nTietueet");
        printf("\n");
        printf("\n1. Kirjoita ohjelma, -jossa on tietue nimeltään Car, jossa seuraavat kentät:");
        printf("\n• brand CHAR(20)");
        printf("\n• model CHAR(50)");
        printf("\n• yearModel INT");
        printf("\n-luo Car-tyyppinen muuttuja nimeltään car_1");
        printf("\n-lisää koodi, jossa käyttäjältä kysytään car_1:n tiedot");
        printf("\n-lisää koodi, jolla tulostetaan car_1:n tiedot");
        printf("\n");
        printf("\n2. Kirjoita ohjelma, jossa on samanlainen tietue Car kuin edellä.");
        printf("\nLuo Car-tyyppinen taulukko, johon voidaan tallentaa 3 alkiota.");
        printf("\nLisää koodi, jolla käyttäjältä kysellään kolmen auton tiedot ja ne tallennetaan em. taulukkoon.");
        printf("\nLisää koodi, jolla em. autojen tiedot tulostetaan ruudulle.");
        printf("\n");
        printf("\n3. Kirjoita ohjelma, joka toimii kuten edellinen sovellus, mutta");
        printf("\nnyt kysytään viiden auton tiedot");
        printf("\nautojen tietoja ei tulosteta ruudulle");
        printf("\nkun autojen tiedot on annettu käyttäjältä kysytään auton merkki(brand) ja tulostetaan kaikki");
        printf("\nkyseisen merkin autojen tiedot. Käyttäjältä kysellään merkkiä, kunnes hän antaa merkiksi");
        printf("\n”LOPETA”.");

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
        }
        if (task_number == 0) {
            printf("\nExiting program...\n");
            break;
        }
    }
    return 0;
}
