#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_csv_to_txt(const char *csv_filename, const char *txt_filename) {
    FILE *csv_file = fopen(csv_filename, "r");
    FILE *txt_file = fopen(txt_filename, "w");

    if (!csv_file || !txt_file) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), csv_file)) {
        char *token = strtok(line, ",");
        if (!token) continue;

        fprintf(txt_file, "%s:", token); // First value is the node

        int first = 1;
        while ((token = strtok(NULL, ",\n")) != NULL) {
            if (!first) fprintf(txt_file, ",");
            fprintf(txt_file, "%s", token);
            first = 0;
        }
        fprintf(txt_file, "\n");
    }

    fclose(csv_file);
    fclose(txt_file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input.csv> <output.txt>\n", argv[0]);
        return 1;
    }

    convert_csv_to_txt(argv[1], argv[2]);
    printf("Conversion completed: %s -> %s\n", argv[1], argv[2]);

    return 0;
}
