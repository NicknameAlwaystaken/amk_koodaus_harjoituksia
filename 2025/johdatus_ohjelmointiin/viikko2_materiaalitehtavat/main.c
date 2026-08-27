#include <stdio.h>

void task_1 () {
    int number;
    printf("Give number: ");
    scanf("%d", &number);

    if( number == 0) {
        printf("Number given is 0.\n");
    } else {
        printf("Number given is NOT 0.\n");
    }
}

void task_2 () {

    int x, y;
    printf("\nGive x: ");
    scanf("%d", &x);

    if ( x >= 1 && x <= 10) {
        printf("x given is between 1 and 10.\n");
    }

    printf("\nGive x: ");
    scanf("%d", &x);

    if ( x < 1 || x > 10) {
        printf("x given is NOT between 1 and 10.\n");
    }

    printf("\nGive x: ");
    scanf("%d", &x);

    printf("\nGive y: ");
    scanf("%d", &y);

    if ( x >= 1 && x <= 10 && ( y < 1 || y > 10)) {
        printf("x given is between 1 and 10 and y is not.\n");
    }
}

void task_3 () {
    int number;
    printf("Give number: ");
    scanf("%d", &number);

    printf("Number given is %s0.\n", number == 0 ? "" : "NOT ");
}

void task_4() {
    int number;
    printf("Give number: ");
    scanf("%d", &number);

    switch (number) {
        case 0: {
            printf("Number given is 0.\n");
            break;
        }
        default: {
            printf("Number given is NOT 0.\n");
            break;
        }
    }
}

int main()
{
	int task_number;
    while(1) {
        printf("\n\nGive task number or give 0 to exit program.\n");
        printf("\n1: Tehtava 4: The Real Thing\n");
        printf("\n2: Tehtava 5: AND vai OR?\n");
        printf("\n3: Tehtava 6: Testaa ternaaria\n");
        printf("\n4: Tehtava 7: Switch it to a switch \n");
        printf("\n\nInput: ");
        scanf("%d", &task_number);
        switch (task_number) {
            case 1: {
                printf("\nTask number: %d\n\n", task_number);
                task_1();
                break;
            }
            case 2: {
                printf("\nTask number: %d\n\n", task_number);
                task_2();
                break;
            }
            case 3: {
                printf("\nTask number: %d\n\n", task_number);
                task_3();
                break;
            }
            case 4: {
                printf("\nTask number: %d\n\n", task_number);
                task_4();
                break;
            }
        }
        if (task_number == 0) {
            printf("\n\nExiting program...\n");
            break;
        }
    }
    return 0;
}
