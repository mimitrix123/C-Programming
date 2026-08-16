#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 100
#define FILE_NAME "student.dat"

struct Student {
    char name[NAME_SIZE];
    int age;
    float marks;
};

int main(void) {
    struct Student student;
    struct Student loaded;
    FILE *file;

    printf("Enter student name: ");
    if (fgets(student.name, sizeof(student.name), stdin) == NULL) {
        return 1;
    }
    student.name[strcspn(student.name, "\n")] = '\0';

    printf("Enter age: ");
    if (scanf("%d", &student.age) != 1) {
        printf("Invalid age.\n");
        return 1;
    }

    printf("Enter marks: ");
    if (scanf("%f", &student.marks) != 1) {
        printf("Invalid marks.\n");
        return 1;
    }

    file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        perror("Unable to open file for writing");
        return 1;
    }

    if (fwrite(&student, sizeof(struct Student), 1, file) != 1) {
        perror("Unable to write student data");
        fclose(file);
        return 1;
    }
    fclose(file);

    file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Unable to open file for reading");
        return 1;
    }

    if (fread(&loaded, sizeof(struct Student), 1, file) != 1) {
        perror("Unable to read student data");
        fclose(file);
        return 1;
    }
    fclose(file);

    printf("\n--- Data Read Back From File ---\n");
    printf("Name : %s\n", loaded.name);
    printf("Age  : %d\n", loaded.age);
    printf("Marks: %.2f\n", loaded.marks);

    return 0;
}
