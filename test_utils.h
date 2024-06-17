#ifndef TEST_UTILS
#define TEST_UTILS

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void prerun(const char* test_name);
void print_header(char* fname);
void print_footer(int passed, int len);
void run_test(int (*test_func)(void (*f)(const char *)), int* passed_ptr);
void run_suite(char* fname, int (*test_funcs[])(void (*)(const char *)) , int len); 

#endif
