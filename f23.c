/*program to read and display the contents of a CSV file named
"data.csv*/

/*
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("data.csv", O_RDONLY);
    char buffer[1024];
    int n;
    while ((n = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, n);
    }
    close(fd);
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        perror("fopen");
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}

