//  Read and display binary file "binary.bin"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("binary.bin", O_RDONLY);
    if (fd < 0) return 1;

    char buf[256];
    int n;
    while ((n = read(fd, buf, sizeof(buf))) > 0)
        write(1, buf, n);

    close(fd);
    return 0;
}

