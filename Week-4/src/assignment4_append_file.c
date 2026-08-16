#include <stdio.h>
#include <string.h>

#define FILE_NAME "append_data.txt"
#define BUFFER_SIZE 500

int main(void) {
    FILE *file;
    char text[BUFFER_SIZE];

    file = fopen(FILE_NAME, "a");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    printf("Enter text to append: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        fclose(file);
        return 1;
    }

    /* Keep each appended entry on its own line. */
    text[strcspn(text, "\n")] = '\0';

    if (fprintf(file, "%s\n", text) < 0) {
        perror("Unable to append data");
        fclose(file);
        return 1;
    }

    fclose(file);
    printf("Data appended successfully to %s\n", FILE_NAME);

    return 0;
}
