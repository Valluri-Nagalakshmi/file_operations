// Create "Backup" directory in the parent directory

#include <stdio.h>
#include <sys/stat.h>

int main() {
    if (mkdir("../Backup", 0777) == -1) {
        perror("mkdir");
        return 1;
    }

    printf("Directory '../Backup' created.\n");
    return 0;
}

