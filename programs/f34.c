// Get the Permissions (mode) of a File

#include <sys/stat.h>
#include <stdio.h>

int main() {
    struct stat st;
    if (stat("file.txt", &st) == -1) {
        perror("stat");
        return 1;
    }

    printf("Permissions: 0%o\n", st.st_mode & 0777);
    return 0;
}

