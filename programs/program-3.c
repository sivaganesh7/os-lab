#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    int sc = 0;

    fp = fopen(argv[1], "r");
    if (fp == NULL)
        printf("Unable to open a file %s", argv[1]);
    else {
        while (!feof(fp)) {
            ch = fgetc(fp);
            if (ch == ' ')
                sc++;
        }
        printf("No of spaces: %d\n", sc);
        fclose(fp);
    }
}
