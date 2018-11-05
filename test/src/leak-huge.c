#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
    int res = 0;

    long unsigned int used = 0;
    do {
        used += 32 * 1024 * 1024;

        int* tmp = malloc(32 * 1024 * 1024);
        if (tmp == NULL)
            break;

        res += tmp[32 * 1024 * 1024 / sizeof(int) - 1];
    } while (used < 64UL * 1024 * 1024);

    printf("FAIL used %lumb\n", used / 1024 / 1024, res);
    return 0;
}
