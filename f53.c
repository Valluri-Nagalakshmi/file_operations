// Create "output.txt" and write "Hello, World!"

#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) return 1;
    write(fd, "Hello, World!\n", 14);
    close(fd);
    return 0;
}

