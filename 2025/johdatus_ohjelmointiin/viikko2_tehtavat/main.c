#include <stdio.h>

void task_1() {
    int input;
    scanf("%d", &input);

    if (input < 10) {
        printf("Annoit luvun joka on pienempi kuin 10.");
    }
}

void task_2() {
    int input1, input2, bigger;
    printf("\nAnna ensimmainen luku: ");
    scanf("%d", &input1);
    printf("\nAnna toinen luku: ");
    scanf("%d", &input2);

    if (input1 < input2) {
        bigger = input2;
    }
    else {
        bigger = input1;
    }

    printf("\nAnnoit luvut %d ja %d, joista %d on suurempi.",input1, input2, bigger);
}

void task_3() {
    char weekdays[7][15] = {
        "Maanantai",
        "Tiistai",
        "Keskiviikko",
        "Torstai",
        "Perjantai",
        "Lauantai",
        "Sunnuntai"
    };

    int input1 = 0;
    printf("\nAnna viikonpäivän numero: ");
    scanf("%d", &input1);

    if (input1 < 8 && input1 > 0) {
        input1--;
        printf("\n%s\n", weekdays[input1]);
    }
    else {
        printf("Annoit sellaisen numeron jolle ei ole viikonpaivaa.");
    }
}

void task_4() {
    int shoppings;
    float discounted_price;
    float discount = 1.0;
    printf("\nKuukauden ostokset: ");
    scanf("%d", &shoppings);
    if (shoppings >= 500) {
        discount -= 0.20;
    } else if (shoppings >= 300) {
        discount -= 0.15;
    } else if (shoppings >= 100) {
				discount -= 0.10;
    }

    discounted_price = shoppings * discount;

    printf("Olet ostanut tässä kuussa %d€:lla ja saat niistä alennusta %f. Ostosten lopullinen summa on %f€", shoppings, 1.0 - discount, discounted_price);
}

void task_5() {
    int id, course1, course2, course3, total_score;
    float average;
    char student_name[20];
    printf("\nID: ");
    scanf("%d", &id);

    printf("\nName: ");
    scanf("%s", student_name);

    printf("\nCourse 1 score: ");
    scanf("%d", &course1);

    printf("\nCourse 2 score: ");
    scanf("%d", &course2);

    printf("\nCourse 3 score: ");
    scanf("%d", &course3);

    total_score = course1 + course2 + course3;

    average = total_score / 3;

    printf("\nIDnumero : %d\n", id);
    printf("Opiskelijan nimi : %s\n", student_name);
    printf("Osasuoritus1 : %d\n", course1);
    printf("Osasuoritus2 : %d\n", course2);
    printf("Osasuoritus3 : %d\n", course3);
    printf("Pisteet yhteensä = %d\n", total_score);
    printf("Keskiarvo = %.2f\n", average);

    if (average >= 80) {
        printf("Arvosanateksti = Kiitettava\n");
    } else if (average >= 60) {
        printf("Arvosanateksti = Hyva\n");
    } else if (average >= 40) {
        printf("Arvosanateksti = Valttava\n");
    }
    else {
        printf("Arvosanateksti = Hylatty\n");
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
        }
        if (task_number == 0) {
            printf("\nExiting program...\n");
            break;
        }
    }
    return 0;
}
