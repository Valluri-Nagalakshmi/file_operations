// Create a directory "Test"

#include <sys/stat.h>
#include <stdio.h>

int main() {
    if (mkdir("Test", 0777) == -1) {
        perror("mkdir");
        return 1;
    }

    return 0;
}

