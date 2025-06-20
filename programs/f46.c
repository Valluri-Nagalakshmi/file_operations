//Copy contents of all .txt files in a directory into "combined.txt"

#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    DIR *dir = opendir(".");
    struct dirent *entry;
    int out = open("combined.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buf[1024];
    int fd, n;

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".txt")) {
            fd = open(entry->d_name, O_RDONLY);
            if (fd < 0) continue;
            while ((n = read(fd, buf, sizeof(buf))) > 0)
                write(out, buf, n);
            close(fd);
        }
    }
    close(out);
    closedir(dir);
    return 0;
}

