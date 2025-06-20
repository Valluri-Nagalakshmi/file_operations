//  Delete "delete_me.txt" from current directory:

#include <unistd.h>
#include <stdio.h>

int main() {
    if (unlink("delete_me.txt") == 0)
        write(1, "Deleted.\n", 9);
    else
        perror("unlink");
    return 0;
}

