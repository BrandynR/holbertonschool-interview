# 0x17. Find the Loop
 Specializations - Interview Preparation ― Algorithms

 by Alexa Orrico, Software Engineer at Holberton School

 Ongoing project - started 10-08-2020, must end by 10-15-2020 (in about 7 hours) - you're done with 0% of tasks.

 Checker was released at 10-11-2020 12:00 PM

 QA review fully automated.

 c floyd algorithm

## Requirements
General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 14.04 LTS
Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
All your files should end with a new line
A README.md file, at the root of the folder of the project is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
No standard library functions allowed. Any use of functions like printf, puts, calloc, realloc etc… is forbidden
In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
The prototypes of all your functions should be included in your header file called lists.h
Don’t forget to push your header file
All your header files should be include guarded
Please use this data structure for this project:
/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
# Tasks

0. Find the loop mandatory
Write a function that finds the loop in a linked list.

Prototype: listint_t *find_listint_loop(listint_t *head);
Returns: The address of the node where the loop starts, or NULL if there is no loop
You are not allowed to use malloc, free or arrays
You can only declare a maximum of two variables in your function
Note: In order to compile the main file, you are provided with this static library. This library won’t be used during the correction; Its only purpose is for testing.
