// program to get the number of files in a directory named "images"

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    DIR *dir = opendir("images");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    struct stat st;
    char path[512];
    int count = 0;

    while ((entry = readdir(dir)) != NULL) {
        snprintf(path, sizeof(path), "images/%s", entry->d_name);
        if (stat(path, &st) == 0 && S_ISREG(st.st_mode)) {
            count++;
        }
    }

    closedir(dir);
    printf("Number of regular files in 'images': %d\n", count);
    return 0;
}

