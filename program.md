# `f1.c` – C Program

This program is part of the file operations system programming examples.

---

## Program Code

```c
// Create new file and write "Hello, World!"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("newfile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    write(fd, "Hello, World!", 13);  // 13 characters
    close(fd);
    return 0;
}


```

---

## How to Compile and Run

```bash
gcc f1.c -o f1
./f1
```



# `f2.c` – C Program

This program is part of the file operations system programming examples.

---

## Program Code

```c
//Open file and display contents

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char buf;
    int fd = open("newfile.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    while (read(fd, &buf, 1) > 0) {
        write(1, &buf, 1);  // write to STDOUT
    }

    close(fd);
    return 0;
}


```

---

## How to Compile and Run

```bash
gcc f2.c -o f2
./f2
```


# `f3.c` – C Program

This program is part of the file operations system programming examples.

---

## Program Code

```c
// Create a directory "Test"

#include <sys/stat.h>
#include <stdio.h>

int main() {
    if (mkdir("Test", 0777) == -1) {
        perror("mkdir");
        return 1;
    }

    return 0;
}


```

---

## How to Compile and Run

```bash
gcc f3.c -o f3
./f3
```

# `f4.c` – C Program

This program is part of the file operations system programming examples.

---

## Program Code

```c
//Check if a file exists

#include <unistd.h>
#include <stdio.h>

int main() {
    if (access("newfile.txt", F_OK) == 0) {
        write(1, "File exists\n", 12);
    } else {
        write(1, "File does not exist\n", 21);
    }

    return 0;
}


```


---

## How to Compile and Run

```bash
gcc f4.c -o f4
./f4
```


# `f5.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
//Rename a file

#include <stdio.h>

int main() {
    if (rename("newfile.txt", "file.txt") == -1) {
        perror("rename");
        return 1;
    }

    return 0;
}


```

---

##  How to Compile and Run

```bash
gcc f5.c -o f5
./f5
```

# `f6.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
//Delete a file

#include <unistd.h>
#include <stdio.h>

int main() {
    if (unlink("txt.txt") == -1) {
        perror("unlink");
        return 1;
    }

    return 0;
}


```

---

##  How to Compile and Run

```bash
gcc f6.c -o f6
./f6
```

# `f7.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
// Copy contents from one file to another

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int src = open("file.txt", O_RDONLY);
    if (src == -1) {
        perror("open source");
        return 1;
    }

    int dest = open("copy.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest == -1) {
        perror("open dest");
        return 1;
    }

    char buf[1024];
    ssize_t n;
    while ((n = read(src, buf, sizeof(buf))) > 0) {
        write(dest, buf, n);
    }

    close(src);
    close(dest);
    return 0;
}


```

---

##  How to Compile and Run

```bash
gcc f7.c -o f7
./f7
```

# `f8.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
// Move file to another directory

#include <stdio.h>

int main() {
    if (rename("copy.txt", "Test/copy.txt") == -1) {
        perror("rename");
        return 1;
    }

    return 0;
}


```

---

##  How to Compile and Run

```bash
gcc f8.c -o f8
./f8
```


# `f9.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
// List all files in current directory

#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    DIR *dir = opendir(".");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        write(1, entry->d_name, strlen(entry->d_name));
        write(1, "\n", 1);
    }

    closedir(dir);
    return 0;
}


```

---

##  How to Compile and Run

```bash
gcc f9.c -o f9
./f9
```


# `f10.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
// Get size of file.txt

#include <sys/stat.h>
#include <stdio.h>

int main() {
    struct stat st;
    if (stat("file.txt", &st) == -1) {
        perror("stat");
        return 1;
    }

    printf("Size: %ld bytes\n", st.st_size);
    return 0;
}


```

---

##  How to Compile and Run

```bash
gcc f10.c -o f10
./f10
```

# `f11.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
// Check if a directory named "Test" exists

#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat st;
    if (stat("Test", &st) == -1) {
        perror("stat");
        return 1;
    }

    if (S_ISDIR(st.st_mode)) {
        printf("'Test' is a directory.\n");
    } else {
        printf("'Test' exists but is not a directory.\n");
    }

    return 0;
}


```

---

##  How to Compile and Run

```bash
gcc f11.c -o f11
./f11
```


# `f12.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
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


```

---

##  How to Compile and Run

```bash
gcc f12.c -o f12
./f12
```


# `f13.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
// Recursively list all files/directories in a given directory

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

void list_recursive(const char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    char fullpath[1024];

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        printf("%s\n", fullpath);

        struct stat st;
        if (stat(fullpath, &st) == 0 && S_ISDIR(st.st_mode)) {
            list_recursive(fullpath);  // Recursive call for subdirectories
        }
    }

    closedir(dir);
}

int main() {
    list_recursive(".");
    return 0;
}


```

---

##  How to Compile and Run

```bash
gcc f13.c -o f13
./f13
```

# `f14.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
// Delete all files in directory "Temp"

#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>

int main() {
    DIR *dir = opendir("Test");
    if (!dir) {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    char filepath[512];

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {  // Regular file
            snprintf(filepath, sizeof(filepath), "Temp/%s", entry->d_name);
            if (unlink(filepath) == -1) {
                perror("unlink");
            } else {
                printf("Deleted: %s\n", filepath);
            }
        }
    }

    closedir(dir);
    return 0;
}


```

---

## 🛠️ How to Compile and Run

```bash
gcc f14.c -o f14
./f14
```


# `f15.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
//  Count the number of lines in a file named "file.txt"

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd = open("file.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char c;
    int count = 0;
    int seen_any = 0;
    while (read(fd, &c, 1) > 0) {
        seen_any = 1;
        if (c == '\n') count++;
    }

    close(fd);
    if (seen_any && c != '\n') count++;  // count last line if not ending in \n

    printf("Line count: %d\n", count);
    return 0;
}


```

---

##  How to Compile and Run

```bash
gcc f15.c -o f15
./f15
```


# `f16.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
//C program to append "Goodbye!" to the end of an existing file named "file.txt"

#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd = open("file.txt", O_WRONLY | O_APPEND);
    if (fd < 0) return 1;
    write(fd, "Goodbye!\n", strlen("Goodbye!\n"));
    close(fd);
    return 0;
}


```

---

##  How to Compile and Run

```bash
gcc f16.c -o f16
./f16
```


# `f17.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
//C program to change the permissions of a file named "file.txt" to read-only.

#include <sys/stat.h>

int main() {
    chmod("file.txt", 0444);
    return 0;
}


```

---

##  How to Compile and Run

```bash
gcc f17.c -o f17
./f17
```


# `f18.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
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


```

---

##  How to Compile and Run

```bash
gcc f18.c -o f18
./f18
```


# `f19.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
// C program to get the last modified timestamp of a file named "file.txt

#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

int main() {
    struct stat st;
    stat("file.txt", &st);
    printf("Last modified: %s", ctime(&st.st_mtime));
    return 0;
}


```

---

##  How to Compile and Run

```bash
gcc f19.c -o f19
./f19
```


# `f20.c` – C Program

This program is part of the file operations system programming examples.

---

##  Program Code

```c
// a C program to create a temporary file and write some data to it

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char tmpname[] = "/home/vallu/linux_pro/file_op/tmpfileXXXXXX";
    int fd = mkstemp(tmpname);
    if (fd == -1) {
        perror("mkstemp failed");
        return 1;
    }
    write(fd, "Temporary data", 14);
    close(fd);
    printf("Temp file created: %s\n", tmpname);
    return 0;
}


```

---

##  How to Compile and Run

```bash
gcc f20.c -o f20
./f20
```


