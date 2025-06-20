// Create symbolic link

#include <unistd.h>
#include <stdio.h>

int main() {
    if (symlink("t.txt","l.txt") == 0)
        write(1, "Symbolic link created\n", 23);
    else
        perror("symlink");
    return 0;
}

