#include <stdlib.h>
#include <stdio.h>
#include "test_utils.h"

void prerun(const char* test_name) {
    printf("\n%s\n", test_name); 
}

void print_header(char* fname) {
    printf("\n---------------\n");
    printf("---------------\n");
    if (fname != NULL) {
        printf("testing %s\n", fname);
    }
}

void print_footer(int passed, int len) {
    printf("\nPASSED %d out of %d tests.\n", passed, len);
    printf("\n---------------\n");
    printf("---------------\n");
}

void run_test(int (*test_func)(void (*f)(const char *)), int* passed_ptr) {
    int status = test_func(&prerun);
    printf("%s\n", status ? ANSI_COLOR_GREEN "PASSED" ANSI_COLOR_RESET : ANSI_COLOR_RED "FAILED" ANSI_COLOR_RESET);  
    if (status == 1) *passed_ptr += 1;
}

void run_suite(char* fname, int (*test_funcs[])(void (*)(const char *)), int len) {
    int* passed_ptr = calloc(1, sizeof(int));

    print_header(fname); 
    for (int i = 0; i < len; i++) {
        run_test(test_funcs[i], passed_ptr);
    }
    print_footer(*passed_ptr, len);
}


