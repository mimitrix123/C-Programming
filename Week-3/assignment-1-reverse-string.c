#include <stdio.h>

void reverseString(char *str) {
    char *start = str;
    char *end = str;
    char temp;

    while (*end != '\0') {
        end++;
    }

    if (end == str) {
        return;
    }

    end--;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main(void) {
    char str[100];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    char *p = str;
    while (*p != '\0') {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
        p++;
    }

    reverseString(str);
    printf("Reversed string: %s\n", str);

    return 0;
}
