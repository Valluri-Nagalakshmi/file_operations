// Read and Display First 10 Lines of "log.txt"
/*
#include <stdio.h>

int main() {
    FILE *fp = fopen("log.txt", "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    char line[512];
    int count = 0;
    while (fgets(line, sizeof(line), fp) && count < 10) {
        printf("%s", line);
        count++;
    }

    fclose(fp);
    return 0;
}
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("log.txt", O_RDONLY);
    if (fd < 0) return 1;

    char c;
    int lines = 0;
    while (read(fd, &c, 1) > 0 && lines < 10) {
        write(1, &c, 1);
        if (c == '\n') lines++;
    }
    close(fd);
    return 0;
}

