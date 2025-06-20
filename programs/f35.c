// Recursively Delete a Directory and Its Contents

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

void delete_dir(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) return;

    struct dirent *entry;
    char fullpath[512];

    while ((entry = readdir(dir))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        struct stat st;
        if (stat(fullpath, &st) == -1) continue;

        if (S_ISDIR(st.st_mode))
            delete_dir(fullpath);
        else
            unlink(fullpath); // delete file
    }

    closedir(dir);
    rmdir(path); // remove the directory itself
}

int main() {
    delete_dir("temp");
    printf("Temp directory deleted.\n");
    return 0;
}

