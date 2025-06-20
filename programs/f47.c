// Recursively calculate total size of all files in a directory and subdirectories

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

long get_dir_size(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) return 0;
    struct dirent *entry;
    struct stat st;
    char fullpath[1024];
    long total = 0;

    while ((entry = readdir(dir))) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) continue;
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        if (lstat(fullpath, &st) == 0) {
            if (S_ISDIR(st.st_mode))
                total += get_dir_size(fullpath);
            else if (S_ISREG(st.st_mode))
                total += st.st_size;
        }
    }
    closedir(dir);
    return total;
}

int main() {
    printf("Total size: %ld bytes\n", get_dir_size("."));
    return 0;
}

