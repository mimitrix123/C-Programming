#include <stdio.h>

int main(void)
{
    int n;
    int positive = 0;
    int negative = 0;
    int zero = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Array size must be positive.\n");
        return 1;
    }

    int arr[n];

    printf("Enter %d integers:\n", n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);

        if (arr[i] > 0)
        {
            positive++;
        }
        else if (arr[i] < 0)
        {
            negative++;
        }
        else
        {
            zero++;
        }
    }

    printf("\nPositive numbers = %d\n", positive);
    printf("Negative numbers = %d\n", negative);
    printf("Zeros = %d\n", zero);

    return 0;
}