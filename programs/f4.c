//Check if a file exists

#include <unistd.h>
#include <stdio.h>

int main() {
    if (access("newfile.txt", F_OK) == 0) {
        write(1, "File exists\n", 12);
    } else {
        write(1, "File does not exist\n", 21);
    }

    return 0;
}

