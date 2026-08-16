#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols, const char *name)
{
    printf("Enter elements of Matrix %s:\n", name);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void addMatrices(
    int a[MAX][MAX],
    int b[MAX][MAX],
    int sum[MAX][MAX],
    int rows,
    int cols
)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}

int main(void)
{
    int rows;
    int cols;

    int a[MAX][MAX];
    int b[MAX][MAX];
    int sum[MAX][MAX];

    printf("Enter rows and columns (max %d): ", MAX);
    scanf("%d %d", &rows, &cols);

    if (rows <= 0 || rows > MAX ||
        cols <= 0 || cols > MAX)
    {
        printf("Rows and columns must be between 1 and %d.\n", MAX);
        return 1;
    }

    inputMatrix(a, rows, cols, "A");

    inputMatrix(b, rows, cols, "B");

    addMatrices(a, b, sum, rows, cols);

    printf("\nMatrix A + Matrix B:\n");

    printMatrix(sum, rows, cols);

    return 0;
}