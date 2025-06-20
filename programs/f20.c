// a C program to create a temporary file and write some data to it

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char tmpname[] = "/home/vallu/linux_pro/file_op/tmpfileXXXXXX";
    int fd = mkstemp(tmpname);
    if (fd == -1) {
        perror("mkstemp failed");
        return 1;
    }
    write(fd, "Temporary data", 14);
    close(fd);
    printf("Temp file created: %s\n", tmpname);
    return 0;
}

