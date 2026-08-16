#include <stdio.h>

int main()
{
    int choice;
    double num1, num2;

    printf("===== SIMPLE CALCULATOR =====\n");

    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    switch (choice)
    {
        case 1:
            printf("Result = %.2lf\n", num1 + num2);
            break;

        case 2:
            printf("Result = %.2lf\n", num1 - num2);
            break;

        case 3:
            printf("Result = %.2lf\n", num1 * num2);
            break;

        case 4:
            if (num2 == 0)
            {
                printf("Error: Cannot divide by zero.\n");
            }
            else
            {
                printf("Result = %.2lf\n", num1 / num2);
            }
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}
