//Read "instructions.txt" and execute commands

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>

int main() {
    int fd = open("instructions.txt", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char buf[256];
    int n, i = 0;

    while ((n = read(fd, &buf[i], 1)) > 0) {
        if (buf[i] == '\n') {
            buf[i] = '\0';          // Null-terminate the command
            if (strlen(buf) > 0) {
                if (fork() == 0) {
                    execlp("/bin/sh", "sh", "-c", buf, NULL);
                    perror("execlp"); // Print error if execlp fails
                    _exit(1);
                } else {
                    wait(NULL); // Parent waits for the child to finish
                }
            }
            i = 0; // Reset buffer index for the next command
        } else {
            i++;
            if (i >= sizeof(buf) - 1) {
                fprintf(stderr, "Command too long!\n");
                return 1;
            }
        }
    }

    // Handle the last line if it doesn't end with a newline
    if (i > 0) {
        buf[i] = '\0';
        if (fork() == 0) {
            execlp("/bin/sh", "sh", "-c", buf, NULL);
            perror("execlp");
            _exit(1);
        } else {
            wait(NULL);
        }
    }

    close(fd);
    return 0;
}


/*
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("instruction.txt", O_RDONLY);
    if (fd < 0) return 1;

    char buf[256];
    int n;
    while ((n = read(fd, buf, sizeof(buf))) > 0)
        write(1, buf, n);

    close(fd);
    return 0;
}
*/
