#include <stdio.h>

unsigned long long factorial(int n)
{
    unsigned long long result = 1;

    for (int i = 2; i <= n; i++)
    {
        result = result * i;
    }

    return result;
}

int main(void)
{
    int n;

    printf("Enter a non-negative integer: ");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Factorial is not defined for negative integers.\n");
        return 1;
    }

    if (n > 20)
    {
        printf("Please enter a value less than or equal to 20.\n");
        return 1;
    }

    printf("%d! = %llu\n", n, factorial(n));

    return 0;
}