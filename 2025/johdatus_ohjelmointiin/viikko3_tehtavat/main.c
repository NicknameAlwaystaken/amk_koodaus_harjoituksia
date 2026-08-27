#include <stdio.h>
#include <stdbool.h>

void task_1() {
    int silmukka_kerrat = 5;
    for (int i = 0; i < silmukka_kerrat; i++ ) {
        // int i = i + 1; i++;
        printf("100\n");
    }
}

void task_2() {
    char name[30];
    int print_count = 5;

    printf("Gif naim plz: ");
    scanf("%s", name);

    printf("Count plox: ");
    scanf("%d", &print_count);

    printf("\nFor loop:\n");

    for (int i = 0; i < print_count; i++ ) {
        printf("%s\n", name);
    }

    printf("\nWhile loop:\n");

    int i = 0;
    while (i < print_count) {
        printf("%s\n", name);
        i++;
    }

    printf("\nDo while loop:\n");

    i = 0;
    do {
        printf("%s\n", name);
        i++;
    } while (i < print_count);
}

void task_3() {
    int correct_number = 17;
    int input_number;

    while(1) {
        printf("Give secret number: ");
        scanf("%d", &input_number);

        printf("\n");
        printf("\n");

        if (input_number == correct_number) {
            printf("Oikein meni, onneksi olkoon, hyva sina!\n");
            break;
        } else {
            printf("Kokeileppa uudestaan!\n");
        }
        printf("\n");
    }
}

void task_4() {

    int max_count = 10;
    int input_number;

    printf("Give number to multiply: ");
    scanf("%d", &input_number);

    for(int i = 0; i < max_count; i++) {
        int current_multiplier = i + 1;
        printf("%d * %d = %d\n", input_number, current_multiplier, current_multiplier * input_number);
    }
}

void task_5() {
    int input_number;
    int sum = 0;
    int even_numbers[100];
    int current_index = 0;
    bool first_number_used = false;

    printf("Give number: ");
    scanf("%d", &input_number);

    while (input_number >= 0) {
        if (input_number % 2 == 0) {
            if (first_number_used) {
                printf(" + ");
            }
            sum += input_number;
            even_numbers[current_index] = input_number;
            printf("%d", input_number);
            current_index++;
            first_number_used = true;
        }
        input_number--;
    }

    printf("\nSum: %d\n", sum);
}

void task_6() {

    /*
    6. Tee ohjelma joka tulostaa käyttäjälle seuraavan valikon, jossa on kolme vaihtoehtoa:
    1. Neliön kehän pituus
    2. Ympyrän kehän pituus
    9. Lopetus.
    Käyttäjä voi valita halutun toiminnan syöttämällä 1,2 tai 9.
    Valinta 1 saa aikaan tulostuksen ”Valittu Neliön kehän pituus”, valinta 2 saa aikaan
    tulostuksen ”Valittu Ympyrän kehän pituus”. Em. tulostuksien jälkeen valikko tulostetaan
    aina uudelleen. Valinta 9 lopettaa ohjelman. (Käytä while-toistorakennetta)
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
                printf("\nValittu nelion kehan pituus");
                break;
            }
            case 2: {
                printf("\nValittu ympyran kehan pituus");
                break;
            }
            case 9: {
                return;
            }
        }
    }
}

int main()
{
	int task_number;
    while(1) {
        printf("\n\nGive task number or give 0 to exit program.\n");
        printf("Input: ");
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
        }
        if (task_number == 0) {
            printf("\nExiting program...\n");
            break;
        }
    }
    return 0;
}
