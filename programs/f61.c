//Count lines in log.txt

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("log.txt", O_RDONLY);
    char ch;
    int count = 0;

    if (fd < 0) return 1;

    while (read(fd, &ch, 1) == 1)
        if (ch == '\n') count++;

    close(fd);
    printf("Lines: %d\n", count);
    return 0;
}

