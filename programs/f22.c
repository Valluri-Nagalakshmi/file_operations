// a C program to create a hard link named "hardlink.txt" to a file named "source.txt

#include <stdio.h>
#include <unistd.h>

int main() {
    const char *existing_file = "file.txt";   // your source file
    const char *hard_link = "data.txt";       // your hard link name

    if (link(existing_file, hard_link) == -1) {
        perror("link");
        return 1;
    }

    printf("Hard link created successfully: %s → %s\n", hard_link, existing_file);
    return 0;
}

