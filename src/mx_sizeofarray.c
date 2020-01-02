#include "libmx.h"

int mx_sizeofarray(char **arr) {
    int size = 0;

    while (arr[size])
        size++;
    return size;
}
