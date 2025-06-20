// Get size of the largest file in current directory

#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    DIR *d = opendir(".");
    struct dirent *entry;
    struct stat st;
    off_t max_size = 0;
    char largest[256] = "";

    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_REG) {
            if (stat(entry->d_name, &st) == 0 && st.st_size > max_size) {
                max_size = st.st_size;
                strcpy(largest, entry->d_name);
            }
        }
    }

    dprintf(1, "Largest file: %s (%ld bytes)\n", largest, max_size);
    closedir(d);
    return 0;
}

