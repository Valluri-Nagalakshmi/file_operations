// Copy contents from one file to another

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int src = open("file.txt", O_RDONLY);
    if (src == -1) {
        perror("open source");
        return 1;
    }

    int dest = open("copy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest == -1) {
        perror("open dest");
        return 1;
    }

    char buf[1024];
    ssize_t n;
    while ((n = read(src, buf, sizeof(buf))) > 0) {
        write(dest, buf, n);
    }

    close(src);
    close(dest);
    return 0;
}

