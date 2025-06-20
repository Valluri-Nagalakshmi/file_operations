// Check if a directory named "Test" exists

#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat st;
    if (stat("Test", &st) == -1) {
        perror("stat");
        return 1;
    }

    if (S_ISDIR(st.st_mode)) {
        printf("'Test' is a directory.\n");
    } else {
        printf("'Test' exists but is not a directory.\n");
    }

    return 0;
}

