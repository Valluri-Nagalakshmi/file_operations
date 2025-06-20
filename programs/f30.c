// Truncate "file.txt" to a specific length (e.g., 50 bytes)

#include <stdio.h>
#include <unistd.h>

int main() {
    if (truncate("file.txt", 100) == -1) {
        perror("truncate");
        return 1;
    }

    printf("file.txt truncated to 100 bytes.\n");
    return 0;
}

