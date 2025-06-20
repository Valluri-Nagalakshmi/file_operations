//Change "important.doc" permissions to read/write for owner only

#include <sys/stat.h>

int main() {
    return chmod("vijaysir_questions.doc", S_IRUSR | S_IWUSR);
}

