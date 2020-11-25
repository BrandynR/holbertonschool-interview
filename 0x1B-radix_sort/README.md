# 0x1B. Radix Sort
For this project you are given the following print_array function:

alexa@ubuntu-xenial:0x1B-radix_sort$ cat `print_array.c`
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
alexa@ubuntu-xenial:0x1B-radix_sort$
Our file print_array.c will be compiled with your function during the correction.
Please declare the prototype of the function print_array in your sort.h header file

## Tasks
### 0. Radix sort mandatory
Write a function that sorts an array of integers in ascending order using the Radix sort algorithm

Prototype: void radix_sort(int *array, size_t size);
You must implement the LSD radix sort algorithm
You can assume that array will contain only numbers >= 0
You are allowed to use malloc and free for this task
You’re expected to print the array each time you increase your significant digit

## (See example below)
alexa@ubuntu-xenial:0x1B-radix_sort$ cat 0-main.c
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
    radix_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alexa@ubuntu-xenial:0x1B-radix_sort$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
alexa@ubuntu-xenial:0x1B-radix_sort$ ./radix
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alexa@ubuntu-xenial:0x1B-radix_sort$