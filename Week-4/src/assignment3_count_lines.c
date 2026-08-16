#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    const char *filename;
    FILE *file;
    int ch;
    long lines = 0;
    int has_content = 0;
    int last_char = '\n';

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    filename = argv[1];
    file = fopen(filename, "r");

    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        has_content = 1;
        if (ch == '\n') {
            lines++;
        }
        last_char = ch;
    }

    fclose(file);

    /* Count a final non-empty line even when it has no trailing newline. */
    if (has_content && last_char != '\n') {
        lines++;
    }

    printf("Number of lines in '%s': %ld\n", filename, lines);
    return 0;
}
