//Rename a file

#include <stdio.h>

int main() {
    if (rename("newfile.txt", "file.txt") == -1) {
        perror("rename");
        return 1;
    }

    return 0;
}

