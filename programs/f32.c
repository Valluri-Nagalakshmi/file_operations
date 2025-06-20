// program to get the file type (regular file, directory, symbolic link, etc.) of a given path
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s </home/vallu/linux_pro/file_op>\n", argv[0]);
        return 1;
    }

    struct stat st;

    if (lstat(argv[1], &st) == -1) {
        perror("lstat");
        return 1;
    }

    if (S_ISREG(st.st_mode))
        printf("Regular file\n");
    else if (S_ISDIR(st.st_mode))
        printf("Directory\n");
    else if (S_ISLNK(st.st_mode))
        printf("Symbolic link\n");
    else if (S_ISCHR(st.st_mode))
        printf("Character device\n");
    else if (S_ISBLK(st.st_mode))
        printf("Block device\n");
    else if (S_ISFIFO(st.st_mode))
        printf("FIFO (named pipe)\n");
    else if (S_ISSOCK(st.st_mode))
        printf("Socket\n");
    else
        printf("Unknown type\n");

    return 0;
}
/*

#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    struct stat st;
    if (lstat("/home/vallu/linux_pro/file_op", &st) == -1) {
        perror("lstat");
        return 1;
    }

    if (S_ISREG(st.st_mode)) write(1, "Regular File\n", 13);
    else if (S_ISDIR(st.st_mode)) write(1, "Directory\n", 10);
    else if (S_ISLNK(st.st_mode)) write(1, "Symlink\n", 8);
    else write(1, "Other\n", 6);
    return 0;
}
*/
