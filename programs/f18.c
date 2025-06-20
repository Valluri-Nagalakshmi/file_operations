// C program to change the ownership of a file named "file.txt" to the user "user1"

#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>

int main() {
    const char *filename = "file.txt";
    const char *new_owner = "vallu";

    // Get UID of user1
    struct passwd *pwd = getpwnam(new_owner);
    if (pwd == NULL) {
        perror("getpwnam failed");
        return 1;
    }

    uid_t new_uid = pwd->pw_uid;
    gid_t new_gid = pwd->pw_gid;

    // Change ownership
    if (chown(filename, new_uid, new_gid) != 0) {
        perror("chown failed");
        return 1;
    }

    printf("Ownership of %s changed to %s\n", filename, new_owner);
    return 0;
}

