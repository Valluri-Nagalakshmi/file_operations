// Copy contents of one file to another:

#include <fcntl.h>
#include <unistd.h>

int main() {
    int in = open("file.txt", O_RDONLY);
    int out = open("d.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buf[1024];
    int n;

    if (in < 0 || out < 0) return 1;

    while ((n = read(in, buf, sizeof(buf))) > 0)
        write(out, buf, n);

    close(in);
    close(out);
    return 0;
}





