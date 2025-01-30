# UNIX System Calls in C

## 1. `fork()` & `getpid()`
This program creates a child process using `fork()` and prints the PID of the parent and child.

```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    } else {
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
    }

    return 0;
}
```

## 2. `exec()`
This program demonstrates replacing the current process with another using `execl()`.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Executing ls command...\n");
    execl("/bin/ls", "ls", "-l", NULL);
    perror("execl failed"); // Will execute only if exec fails
    return 1;
}
```

## 3. `exit()`
This program uses `exit()` to terminate a process with a specific status.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Program is exiting with status 0\n");
    exit(0);
}
```

## 4. `wait()`
This program makes the parent process wait for the child process to complete.

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child process executing...\n");
        sleep(2);
        printf("Child process exiting...\n");
        exit(42);
    } else {
        int status;
        wait(&status);
        printf("Parent: Child exited with status %d\n", WEXITSTATUS(status));
    }

    return 0;
}
```

## 5. `close()`
This program opens a file, writes to it, and then closes it.

```c
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("testfile.txt", O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        perror("File open failed");
        return 1;
    }

    write(fd, "Hello, UNIX System Calls!\n", 26);
    close(fd);
    printf("File closed successfully\n");

    return 0;
}
```

## 6. `stat()`
This program retrieves file metadata using `stat()`.

```c
#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat fileStat;
    if (stat("testfile.txt", &fileStat) < 0) {
        perror("stat failed");
        return 1;
    }

    printf("File size: %ld bytes\n", fileStat.st_size);
    printf("Number of links: %ld\n", fileStat.st_nlink);
    printf("File permissions: %o\n", fileStat.st_mode);

    return 0;
}
```

## 7. `opendir()` & `readdir()`
This program lists the contents of a directory.

```c
#include <stdio.h>
#include <dirent.h>

int main() {
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("opendir failed");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);
    return 0;
}
