// Create directory named "Documents"


#include <sys/stat.h>
#include <stdio.h>

int main() {
    if (mkdir("Documents", 0755) == 0)
        printf("Documents directory created.\n");
    else
        perror("mkdir");
    return 0;
}

