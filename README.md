# C Test Utils

Simple util file to run test functions with slightly better formatting. The ```example.c``` file shows how you can use the given interface to run some tests.
```bash
$ gcc -o example example.c test_utils.c
$ ./example

---------------
---------------
testing example.c

test_add_a
PASSED

test_add_b
PASSED

test_add_overflows
FAILED

PASSED 2 out of 3 tests.

---------------
---------------
```
