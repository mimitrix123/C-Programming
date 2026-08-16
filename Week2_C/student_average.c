#include <stdio.h>

// Function to calculate average
float calculateAverage(float marks[], int subjects)
{
    float total = 0;

    for (int i = 0; i < subjects; i++)
    {
        total = total + marks[i];
    }

    return total / subjects;
}

// Function to calculate grade
char calculateGrade(float average)
{
    if (average >= 90)
    {
        return 'A';
    }
    else if (average >= 80)
    {
        return 'B';
    }
    else if (average >= 70)
    {
        return 'C';
    }
    else if (average >= 60)
    {
        return 'D';
    }
    else
    {
        return 'F';
    }
}

int main()
{
    char name[50];
    int subjects;
    float marks[100];
    float average;
    char grade;

    printf("=================================\n");
    printf("     STUDENT AVERAGE CALCULATOR\n");
    printf("=================================\n");

    // Get student name
    printf("Enter student name: ");
    scanf("%49s", name);

    // Get number of subjects
    printf("Enter number of subjects: ");
    scanf("%d", &subjects);

    // Validate number of subjects
    if (subjects <= 0 || subjects > 100)
    {
        printf("Invalid number of subjects!\n");
        return 1;
    }

    // Get and validate marks
    for (int i = 0; i < subjects; i++)
    {
        do
        {
            printf("Enter marks for subject %d (0-100): ", i + 1);
            scanf("%f", &marks[i]);

            if (marks[i] < 0 || marks[i] > 100)
            {
                printf("Invalid marks! Please enter marks between 0 and 100.\n");
            }

        } while (marks[i] < 0 || marks[i] > 100);
    }

    // Calculate average
    average = calculateAverage(marks, subjects);

    // Calculate grade
    grade = calculateGrade(average);

    // Display result
    printf("\n=================================\n");
    printf("              RESULT\n");
    printf("=================================\n");

    printf("Student Name : %s\n", name);
    printf("Subjects     : %d\n", subjects);
    printf("Average      : %.2f\n", average);
    printf("Grade        : %c\n", grade);

    printf("=================================\n");

    return 0;
}