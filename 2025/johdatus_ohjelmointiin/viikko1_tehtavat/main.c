#include <stdio.h>

void task_1() {
    float float_variable = 1.0;
    int int_variable = 2;
    char char_variable = 'c';

    printf("float_variable = %f\n", float_variable);
    printf("int_variable = %i\n", int_variable);
    printf("char_variable = %c\n", char_variable);
}

void task_2() {
    float temperature_c, temperature_f;
    printf("\nAnna C asteita: ");
    scanf("%f", &temperature_c);
    temperature_f = temperature_c * 1.8 + 32;
	printf("Antamasi lampotila %f on Farenheit asteina %f.\n", temperature_c, temperature_f);
}

void task_3() {
    float triangle_width, triangle_height, triangle_area;
    printf("\nAnna kolmion kanta: ");
    scanf("%f", &triangle_width);
    printf("\nAnna kolmion korkeus: ");
    scanf("%f", &triangle_height);

    triangle_area = (triangle_width * triangle_height) / 2;

    printf("\nKun kolmion kanta on %fm ja korkeus %fm, on kolmion ala %fm2.\n", triangle_width, triangle_height, triangle_area);
}
void task_4() {
    float first_number, second_number;
    printf("\nAnna eka numero: ");
    scanf("%f", &first_number);
    printf("\nAnna toka numero: ");
    scanf("%f", &second_number);

    printf("\nSyotetyt luvut olivat %f ja %f.", first_number, second_number);
    printf("\nLukujen summa on %f.", first_number + second_number);
    printf("\nLukujen erotus %f.", first_number - second_number);
    printf("\nLukujen tulo %f.", first_number * second_number);
    printf("\nLukujen osamäärä %f.", first_number / second_number);
}

void task_5 () {
    int array[3][3];
    for (int y = 0; y < 3; y++) {
        for(int x = 0; x < 3; x++) {
            int number;
            printf("\nSyota numero: ");
            scanf("%d", &number);
            array[y][x] = number;
        }
    }

    printf("\nTaulukon 1. rivin luku on %d", array[0][2]);
    printf("\nTaulukon 2. rivin luku on %d", array[1][1]);
    printf("\nTaulukon 3. rivin luku on %d", array[2][0]);
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
