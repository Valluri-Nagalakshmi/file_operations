// Create symbolic link "shortcut.txt" to "target.txt"

#include <unistd.h>

int main() {
    return symlink("target.txt", "shortcut.txt");
}

