// Check if "file.txt" exists in current directory

#include <unistd.h>
#include <stdio.h>

int main() {
    if (access("file.txt", F_OK) == 0)
        write(1, "Exists\n", 7);
    else
        write(1, "Does not exist\n", 16);
    return 0;
}

