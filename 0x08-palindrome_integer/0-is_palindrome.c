#include "palindrome.h"

/**
 * is_palindrome - checks whether or not a given unsigned integer is a palindrome
 * @n: is the number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long first, last, divide = 1;

	while (n / divide >= 10)
		divide *= 10;

	while (n != 0)
	{
		first = n / divide;
		last = n % 10;

		if (first != last)
			return (0);

		n = (n % divide) / 10;

		divide /= 100;
	}
	return (1);
}
