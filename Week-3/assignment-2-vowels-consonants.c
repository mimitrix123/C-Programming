#include <stdio.h>

int isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}

int isLetter(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int main(void) {
    char str[200];
    int vowels = 0;
    int consonants = 0;
    char *p;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    p = str;
    while (*p != '\0') {
        if (isLetter(*p)) {
            if (isVowel(*p)) {
                vowels++;
            } else {
                consonants++;
            }
        }
        p++;
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}
