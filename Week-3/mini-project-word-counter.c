#include <stdio.h>

int countWords(const char *text) {
    int count = 0;
    int inWord = 0;
    const char *p = text;

    while (*p != '\0') {
        if (*p != ' ' && *p != '\t' && *p != '\n' && *p != '\r') {
            if (!inWord) {
                count++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
        p++;
    }

    return count;
}

int main(void) {
    char text[500];

    printf("Enter a sentence: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        return 1;
    }

    printf("Number of words: %d\n", countWords(text));

    return 0;
}
