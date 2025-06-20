// C program to get the size of a directory named "file_op"

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

long get_directory_size(const char *path) {
    long total_size = 0;
    struct dirent *entry;
    DIR *dir = opendir(path);

    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    char filepath[1024];
    struct stat st;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(filepath, sizeof(filepath), "%s/%s", path, entry->d_name);
        if (stat(filepath, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                total_size += get_directory_size(filepath); // recurse
            } else {
                total_size += st.st_size;
            }
        }
    }

    closedir(dir);
    return total_size;
}

int main() {
    const char *dir = "Test";
    long size = get_directory_size(dir);
    if (size >= 0) {
        printf("Total size of '%s': %ld bytes\n", dir, size);
    }
    return 0;
}
*/

#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

int main() {
    DIR *dir = opendir("Test");
    struct dirent *entry;
    struct stat st;
    char path[512];
    long total = 0;

    while ((entry = readdir(dir)) != NULL) {
        snprintf(path, sizeof(path), "Test/%s", entry->d_name);
        if (stat(path, &st) == 0 && S_ISREG(st.st_mode)) {
            total += st.st_size;
        }
    }
    closedir(dir);
    printf("Total size: %ld bytes\n", total);
    return 0;
}

