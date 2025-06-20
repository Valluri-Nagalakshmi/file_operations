// C program to get the last modified timestamp of a file named "file.txt

#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

int main() {
    struct stat st;
    stat("file.txt", &st);
    printf("Last modified: %s", ctime(&st.st_mtime));
    return 0;
}

