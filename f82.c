//  Display binary file in hexadecimal

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("data.bin", O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    unsigned char buffer[16];
    int bytesRead;
    int offset = 0;

    while ((bytesRead = read(fd, buffer, sizeof(buffer))) > 0) {
        // Print offset
        dprintf(1, "%08x  ", offset);

        // Print hex bytes
        for (int i = 0; i < 16; i++) {
            if (i < bytesRead)
                dprintf(1, "%02x ", buffer[i]);
            else
                write(1, "   ", 3);

            if (i == 7) write(1, " ", 1);
        }

        write(1, " |", 2);
        // Print ASCII characters
        for (int i = 0; i < bytesRead; i++) {
            char c = buffer[i];
            if (c >= 32 && c <= 126)
                write(1, &c, 1);
            else
                write(1, ".", 1);
        }
        write(1, "|\n", 2);

        offset += bytesRead;
    }

    close(fd);
    return 0;
}

