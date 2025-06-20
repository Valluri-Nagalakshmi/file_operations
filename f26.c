// C program to recursively copy all files and directories from one directory to another 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

void copy_file(const char *src, const char *dest) {
    int in = open(src, O_RDONLY);
    if (in == -1) {
        perror("open src");
        return;
    }

    int out = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (out == -1) {
        perror("open dest");
        close(in);
        return;
    }

    char buf[1024];
    ssize_t bytes;
    while ((bytes = read(in, buf, sizeof(buf))) > 0) {
        write(out, buf, bytes);
    }

    close(in);
    close(out);
}

void copy_directory(const char *src_dir, const char *dest_dir) {
    mkdir(dest_dir, 0755);
    DIR *dir = opendir(src_dir);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    char src_path[1024], dest_path[1024];

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(src_path, sizeof(src_path), "%s/%s", src_dir, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest_dir, entry->d_name);

        struct stat st;
        if (stat(src_path, &st) == 0) {
            if (S_ISDIR(st.st_mode)) {
                copy_directory(src_path, dest_path); // recursion
            } else {
                copy_file(src_path, dest_path);
            }
        }
    }

    closedir(dir);
}

int main() {
    const char *source = "Test";
    const char *destination = "temp";

    copy_directory(source, destination);
    printf("Directory copied successfully.\n");
    return 0;
}

