// Get number of hard links to "file.txt"

#include <sys/stat.h>
#include <stdio.h>

int main() {
    struct stat st;
    if (stat("file.txt", &st) == 0) {
        dprintf(1, "Hard Links: %lu\n", st.st_nlink);
    } else {
        perror("stat");
    }
    return 0;
}

