// Create "notes.txt" and write multiple lines

#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("notes.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0) return 1;

    char *lines[] = {
        "This is line one.\n",
        "This is line two.\n",
        "This is line three.\n"
    };
    for (int i = 0; i < 3; i++)
        write(fd, lines[i], strlen(lines[i]));

    close(fd);
    return 0;
}

