#include <stdio.h>
#include <string.h>

#define NAME_SIZE 100

struct Student {
    char name[NAME_SIZE];
    int age;
    float marks;
};

int main(void) {
    struct Student student;

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

    printf("\n--- Student Details ---\n");
    printf("Name : %s\n", student.name);
    printf("Age  : %d\n", student.age);
    printf("Marks: %.2f\n", student.marks);

    return 0;
}
