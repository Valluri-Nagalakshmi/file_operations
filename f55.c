// Rename "old_name.txt" to "new_name.txt"

#include <stdio.h>

int main() {
    if (rename("old_name.txt", "new_name.txt") == 0)
        write(1, "Renamed successfully\n", 22);
    else
        perror("rename");
    return 0;
}

