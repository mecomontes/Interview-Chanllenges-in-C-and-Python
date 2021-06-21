# 0x18. Merge Sort

-----
### [0. Merge sort](./0-merge_sort.c)
Write a function that sorts an array of integers in ascending order using the [Merge Sort] algorithm:

-   Prototype: `void merge_sort(int *array, size_t size);`
-   You must implement the `top-down` merge sort algorithm
    -   When you divide an array into two sub-arrays, the size of the left array should always be <= the size of the right array. i.e. `{1, 2, 3, 4, 5}` -> `{1, 2}, {3, 4, 5}`
    -   Sort the left array before the right array
-   You are allowed to use `printf`
-   You are allowed to use `malloc` and `free` only once (only one **call**)
-   Output: see example

```
alexa@ubuntu-xenial:0x18-merge_sort$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    merge_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alexa@ubuntu-xenial:0x18-merge_sort$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
alexa@ubuntu-xenial:0x18-merge_sort$ ./merge
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
Merging...
[left]: 71
[right]: 13
[Done]: 13, 71
Merging...
[left]: 99
[right]: 13, 71
[Done]: 13, 71, 99
Merging...
[left]: 19, 48
[right]: 13, 71, 99
[Done]: 13, 19, 48, 71, 99
Merging...
[left]: 52
[right]: 96
[Done]: 52, 96
Merging...
[left]: 86
[right]: 7
[Done]: 7, 86
Merging...
[left]: 73
[right]: 7, 86
[Done]: 7, 73, 86
Merging...
[left]: 52, 96
[right]: 7, 73, 86
[Done]: 7, 52, 73, 86, 96
Merging...
[left]: 13, 19, 48, 71, 99
[right]: 7, 52, 73, 86, 96
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alexa@ubuntu-xenial:0x18-merge_sort$
```
---
## Authors

* **Robinson Montes** - [mecomonteshbtn](https://github.com/mecomonteshbtn)
