// C program to get the absolute path of the current working directory

#include <stdio.h>
#include <unistd.h>

int main() {
    char path[1024];
    if (getcwd(path, sizeof(path)) != NULL) {
        printf("Current working directory: %s\n", path);
    } else {
        perror("getcwd");
        return 1;
    }
    return 0;
}

