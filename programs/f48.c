// Get number of bytes in "data.bin"

#include <sys/stat.h>
#include <stdio.h>

int main() {
    struct stat st;
    if (stat("data.bin", &st) == 0)
        printf("Size: %ld bytes\n", st.st_size);
    else
        perror("stat");
    return 0;
}

