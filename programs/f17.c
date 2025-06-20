//C program to change the permissions of a file named "file.txt" to read-only.

#include <sys/stat.h>

int main() {
    chmod("file.txt", 0444);
    return 0;
}

