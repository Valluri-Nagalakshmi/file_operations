//  Check if "config.ini" is writable

#include <unistd.h>

int main() {
    if (access("config.ini", W_OK) == 0)
        write(1, "Writable\n", 9);
    else
        write(1, "Not Writable\n", 13);
    return 0;
}


