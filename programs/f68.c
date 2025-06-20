//Implement a C program to get the size of a file named "image.jpg"

#include <sys/stat.h>
#include <stdio.h>

int main() {
    struct stat st;
    if (stat("image.jpg.png", &st) == 0)
        printf("Size: %ld bytes\n", st.st_size);
    else
        perror("stat");
    return 0;
}

