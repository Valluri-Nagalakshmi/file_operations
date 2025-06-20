//  Check if "data.txt" is readable

#include <unistd.h>

int main() {
    if (access("data.txt", R_OK) == 0)
        write(1, "Readable\n", 9);
    else
        write(1, "Not Readable\n", 13);
    return 0;
}

