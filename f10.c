// Get size of file.txt

#include <sys/stat.h>
#include <stdio.h>

int main() {
    struct stat st;
    if (stat("file.txt", &st) == -1) {
        perror("stat");
        return 1;
    }

    printf("Size: %ld bytes\n", st.st_size);
    return 0;
}

