// List all files in current directory

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        write(1, entry->d_name, strlen(entry->d_name));
        write(1, "\n", 1);
    }

    closedir(dir);
    return 0;
}

