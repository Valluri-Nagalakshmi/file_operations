// Create new file and write "Hello, World!"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("newfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    write(fd, "Hello, World!", 13);  // 13 characters
    close(fd);
    return 0;
}

