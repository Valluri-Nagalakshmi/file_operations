//Create "Logs" directory and move all .log files into it


#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

int main() {
    mkdir("Logs", 0755);
    DIR *d = opendir(".");
    struct dirent *de;

    while ((de = readdir(d)) != NULL) {
        if (strstr(de->d_name, ".log")) {
            char newpath[256];
            snprintf(newpath, sizeof(newpath), "Logs/%s", de->d_name);
            rename(de->d_name, newpath);
        }
    }

    closedir(d);
    return 0;
}

