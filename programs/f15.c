//  Count the number of lines in a file named "file.txt"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char c;
    int count = 0;
    int seen_any = 0;
    while (read(fd, &c, 1) > 0) {
        seen_any = 1;
        if (c == '\n') count++;
    }

    close(fd);
    if (seen_any && c != '\n') count++;  // count last line if not ending in \n

    printf("Line count: %d\n", count);
    return 0;
}

