// Create a FIFO named "myfifo" in current directory

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    if (mkfifo("myfifo", 0666) == -1) {
        perror("mkfifo");
        return 1;
    }

    printf("FIFO 'myfifo' created successfully.\n");
    return 0;
}

