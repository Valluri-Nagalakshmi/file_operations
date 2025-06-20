// program to search for a specific string in a file named "data.txt" and display the line number(s) where it occurs

#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("file.txt", "r");
    if (!file) {
        perror("fopen");
        return 1;
    }

    char line[1024];
    char target[] = "POSIX";  // Change this to the string to find
    int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;
        if (strstr(line, target)) {
            printf("String found at line: %d\n", line_number);
        }
    }

    fclose(file);
    return 0;
}

