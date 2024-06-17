#include <math.h>
#include <limits.h>

#include "test_utils.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int test_add_a(void (*prefun)(const char *)) {
    prefun(__func__);
    return add(1, 2) == 3;
}

int test_add_b(void (*prefun)(const char *)) {
    prefun(__func__);
    return add(3, 2) == 5;
}

int test_add_overflows(void (*prefun)(const char *)) {
    prefun(__func__);
    return add(INT_MAX, 1) == 2147483648;
}

void main() {
    void* tests[] = {
        test_add_a,
        test_add_b,
        test_add_overflows
    };

    run_suite("example.c", tests, 3);
}
