//Read data from FIFO "myfifo"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char buffer[1024];
    int fd = open("myfifo", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    ssize_t bytesRead;
    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0';  // Null-terminate
        printf("Received: %s", buffer);
    }

    close(fd);
    return 0;
}

