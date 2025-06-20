//Create a directory with today's date "YYYY-MM-DD"

#include <time.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    char dirname[64];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(dirname, sizeof(dirname), "%Y-%m-%d", tm);

    if (mkdir(dirname, 0755) == -1) {
        perror("mkdir");
        return 1;
    }
    printf("directory is created with today's date\n");
    return 0;
}

