//Delete a file

#include <unistd.h>
#include <stdio.h>

int main() {
    if (unlink("txt.txt") == -1) {
        perror("unlink");
        return 1;
    }

    return 0;
}

