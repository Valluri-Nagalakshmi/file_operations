//Copy "input.txt" to "output.txt" in Reverse Order (Line-wise)

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin = fopen("log.txt", "rb");
    FILE *fout = fopen("output.txt", "w");

    if (!fin || !fout) {
        perror("File open error");
        return 1;
    }

    // Seek to end of input file
    fseek(fin, 0, SEEK_END);
    long filesize = ftell(fin);  // get file size
    rewind(fin); // reset to start (optional here)

    // Read whole file into buffer
    char *buffer = malloc(filesize);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(fin);
        fclose(fout);
        return 1;
    }

    fread(buffer, 1, filesize, fin);

    // Write contents in reverse to output file
    for (long i = filesize - 1; i >= 0; i--) {
        fputc(buffer[i], fout);
    }

    // Cleanup
    free(buffer);
    fclose(fin);
    fclose(fout);

    printf("Reversed file content written to output.txt\n");

    return 0;
}

