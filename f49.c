//Create directory with current timestamp (YYYY-MM-DD-HH-MM-SS):

#include <time.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    char dirname[64];
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    strftime(dirname, sizeof(dirname), "%Y-%m-%d-%H-%M-%S", tm);
    if (mkdir(dirname, 0755) == 0)
        printf("Directory created: %s\n", dirname);
    else
        perror("mkdir");
    return 0;
}

