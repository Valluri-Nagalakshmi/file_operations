// Delete all files in directory "Temp"

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    DIR *dir = opendir("Test");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    char filepath[512];

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {  // Regular file
            snprintf(filepath, sizeof(filepath), "Temp/%s", entry->d_name);
            if (unlink(filepath) == -1) {
                perror("unlink");
            } else {
                printf("Deleted: %s\n", filepath);
            }
        }
    }

    closedir(dir);
    return 0;
}

