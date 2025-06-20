// Create a New Empty File named "empty.txt"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("empty.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    close(fd);
    printf("empty.txt created.\n");
    return 0;
}

