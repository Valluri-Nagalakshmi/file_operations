//Open file and display contents

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char buf;
    int fd = open("newfile.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    while (read(fd, &buf, 1) > 0) {
        write(1, &buf, 1);  // write to STDOUT
    }

    close(fd);
    return 0;
}

