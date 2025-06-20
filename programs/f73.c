//Get last access time of "data.txt"

#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

int main() {
    struct stat st;
    if (stat("data.txt", &st) == -1) return 1;

    printf("Last access: %s", ctime(&st.st_atime));
    return 0;
}

