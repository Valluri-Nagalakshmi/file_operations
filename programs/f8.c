// Move file to another directory

#include <stdio.h>

int main() {
    if (rename("copy.txt", "Test/copy.txt") == -1) {
        perror("rename");
        return 1;
    }

    return 0;
}

