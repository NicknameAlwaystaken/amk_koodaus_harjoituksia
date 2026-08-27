#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Student {
    int id;
    char name[50];
    int age;
};

void task_1() {

    char uusi_nimi[20];
    printf("Anna nimesi: ");
    scanf("%s", uusi_nimi);

    FILE *fptr;

    fptr = fopen("teht1.txt", "w");
    if (!fptr) {
        perror("teht1.txt open failed");
        return;
    }
    fprintf(fptr, "%s", uusi_nimi);

    fclose(fptr);
}

void task_2() {
    char file_text[100];
    char output_text[100];

    FILE *readfptr;
    FILE *writefptr;

    readfptr = fopen("source.txt", "r");
    if (!readfptr) { // jos avaaminen epäonnistuu niin annetaan errori
        perror("source.txt open failed");
        return;
    }

    writefptr = fopen("target.txt", "w");
    if (!writefptr) {
        // sama kuin source.txt
        // mutta myös suljetaan readfptr kun sitä ei käytetä
        perror("target.txt open failed");
        fclose(readfptr);
        return;
    }

    while(fgets(file_text, 100, readfptr)) {
        strcpy(output_text, file_text);
        for(int i = 0; i < sizeof(output_text); i++) {
            if (output_text[i] == ',') {
                output_text[i] = '.';
            }
        }
        fprintf(writefptr, "%s", output_text);
    }

    fclose(readfptr);
    fclose(writefptr);
}

void task_3() {
    char file_text[100];

    FILE *readfptr;

    readfptr = fopen("source.txt", "r");
    if (!readfptr) { // jos avaaminen epäonnistuu niin annetaan errori
        perror("source.txt open failed");
        return;
    }

    int rivien_maara = 0;
    int sanojen_maara = 0;
    while(fgets(file_text, 100, readfptr)) {
        char *token;
        char *text = file_text;
        while((token = strtok_r(text, " ", &text))) {
            sanojen_maara++;
        }
        rivien_maara++;
    }

    fclose(readfptr);

    printf("\nRivien maara: %d", rivien_maara);
    printf("\nSanojen maara: %d", sanojen_maara);
    printf("\n");
}

void task_4() {

    int student_count = 5;
    struct Student students[student_count];

    for (int i = 0; i < student_count; i++) {
        printf("\n");
        printf("\nOpiskelija id: ");
        scanf("%d", &students[i].id);
        printf("\nOpiskelija nimi: ");
        scanf("%s", students[i].name);
        printf("\nOpiskelija ika: ");
        scanf("%d", &students[i].age);
    }

    for (int i = 0; i < student_count; i++) {
        printf("\n");
        printf("\nID: %d", students[i].id);
        printf("\nNimi: %s", students[i].name);
        printf("\nIka: %d", students[i].age);
    }
}

void task_5() {
    char output_text[100];

    FILE *writefptr;

    int student_count = 5;
    struct Student students[student_count];

    for (int i = 0; i < student_count; i++) {
        printf("\n");
        printf("\nOpiskelija id: ");
        scanf("%d", &students[i].id);
        printf("\nOpiskelija nimi: ");
        scanf("%s", students[i].name);
        printf("\nOpiskelija ika: ");
        scanf("%d", &students[i].age);
    }

    writefptr = fopen("/var/tmp/students_data.txt", "w");

    if (!writefptr) {
        perror("target.txt open failed");
        return;
    }

    int vastaus;
    printf("\nHaluatko tallentaa tietoa? (Kylla=1/Ei=2)\n");
    scanf("%d", &vastaus);

    for (int i = 0; i < student_count; i++) {
        printf("\n");
        printf("\nID: %d", students[i].id);
        printf("\nNimi: %s", students[i].name);
        printf("\nIka: %d", students[i].age);

        if (vastaus == 1) {
            fprintf(writefptr, "%d,%s,%d\n", students[i].id, students[i].name, students[i].age);
        }
    }

    printf("\n");

    fclose(writefptr);
}

void task_6() {
    char file_text[100];
    char student_data[3][20];

    FILE *readfptr;

    bool found = false;

    char haettava_id[10];
    printf("\nHae opiskelija ID:llä: ");
    scanf("%s", haettava_id);

    readfptr = fopen("/var/tmp/students_data.txt", "r");
    if (!readfptr) { // jos avaaminen epäonnistuu niin annetaan errori
        perror("students_data.txt open failed");
        return;
    }

    while(fgets(file_text, 100, readfptr)) {
        bool first_token = true;
        char *token;
        char *text = file_text;
        int i = 0;
        while((token = strtok_r(text, ",", &text))) {
            if (!found && first_token) {
                printf("\nfirst_token: %s\n", token);
                if (strcmp(token, haettava_id) == 0) {
                    found = true;
                } else {
                    break;
                }
                first_token = false;
            }
            strcpy(student_data[i], token);
            i++;
        }
        if (found) {
            break;
        }
    }

    if (found) {
        printf("\n");
        printf("\nID: %s", student_data[0]);
        printf("\nNimi: %s", student_data[1]);
        printf("\nIka: %s", student_data[2]);
        printf("\n");
    } else {
        printf("\nEi loytynyt IDlla: %s\n", haettava_id);
    }

    fclose(readfptr);
}

int main()
{
    int task_number;
    while(1) {
        printf("Tiedostojen käsittely\n");
        printf("1. Kirjoita ohjelma, joka kysyy käyttäjän nimen ja tallentaa sen tiedostoon.\n");
        printf("\n");
        printf("2. Luo jollain editorilla (esim. Notepad) tiedosto nimeltään source.txt jossa seuraavat tiedot\n");
        printf("\n");
        printf("3. Kirjoita ohjelma, joka laskee tiedostossa olevien sanojen ja rivien määrän.\n");
        printf("\n");
        printf("4. Kirjoita ohjelma,\n");
        printf("\n");
        printf("5. Kirjoita ohjelma, joka toimii kuten edellinen sovellus, mutta lopuksi ohjelma kysyy:\n");
        printf("\n");
        printf("6. Kirjoita ohjelma, joka kysyy käyttäjältä opiskelijan ID:n. Sitten ohjelma etsii tiedostosta\n");

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
        }
        if (task_number == 0) {
            printf("\nExiting program...\n");
            break;
        }
    }
    return 0;
}
