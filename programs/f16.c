//C program to append "Goodbye!" to the end of an existing file named "file.txt"

#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("file.txt", O_WRONLY | O_APPEND);
    if (fd < 0) return 1;
    write(fd, "Goodbye!\n", strlen("Goodbye!\n"));
    close(fd);
    return 0;
}

