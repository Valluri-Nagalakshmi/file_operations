// Count words in "notes.txt"

#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>
#include <stdio.h>

int main() {
    int fd = open("notes.txt", O_RDONLY);
    if (fd < 0) return 1;

    char c;
    int in_word = 0, words = 0;
    while (read(fd, &c, 1) > 0) {
        if (isspace(c)) in_word = 0;
        else if (!in_word) {
            in_word = 1;
            words++;
        }
    }
    close(fd);
    printf("Words: %d\n", words);
    return 0;
}

