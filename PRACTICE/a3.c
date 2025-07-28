#include <stdio.h>
#include <string.h>

int main() {
    char line[256];
    FILE *fp = fopen("vehicle_data.txt", "r");
    if (!fp) {
        printf("Cannot open file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)) {
        // Skip leading spaces/tabs
        char *ptr = line;
        while (*ptr == ' ' || *ptr == '\t') ptr++;

        // Skip comments and empty lines
        if (*ptr == '#' || *ptr == '\n' || *ptr == '\0')
            continue;

        // Remove trailing newline
        ptr[strcspn(ptr, "\n")] = '\0';

        printf("Data line: %s\n", ptr);
    }

    fclose(fp);
    return 0;
}