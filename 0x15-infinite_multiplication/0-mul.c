#include <stdlib.h>
#include "holberton.h"

#define _INT_MAX 4294967295u

/**
 * print_int - print integer from string
 * @str: string stores number to print
 */
void print_int(char *str)
{
	char leading = 1;

	while (*str != '\0')
	{
		if (!leading || *str != '0')
			_putchar(*str);
		if (*str != '0')
			leading = 0;
		str++;
	}
	if (leading)
		_putchar('0');
}

/**
 * isnumeric - checks if a string is numeric
 * @str: string to check
 * Return: string length if numeric
 */
unsigned int isnumeric(char *str)
{
	unsigned int ret = 0;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		ret++;
		str++;
	}
	return (ret);
}

/**
 * add_em - add two numbers
 * @frst: first operand
 * @sec: second operand
 * @power: order of magnitude of 'sec'
 * @len: length of operands
 */
void add_em(char *frst, unsigned int sec, unsigned int power, unsigned int len)
{
	char carry = 0;
	unsigned int index, isum;

	index = len - power - 1;
	isum = frst[index] - '0' + sec % 10;
	if (isum >= 10)
		carry = 1;
	frst[index] = isum % 10 + '0';
	index--;
	isum = frst[index] - '0' + sec / 10 + carry;
	if (isum >= 10)
		carry = 1;
	else
		carry = 0;
	frst[index] = isum % 10 + '0';
	index--;
	while (carry)
	{
		isum = frst[index] - '0' + carry;
		if (isum < 10)
			carry = 0;
		frst[index] = isum % 10 + '0';
		index--;
	}
}

/**
 * mult - multiply two numbers
 * @first: first operand
 * @len1: length of first operand
 * @sec: second operand
 * @len2: length seocnd operand
 * @sum: string stores sum of product
 * @lsum: length of sum
 */
void mult(
		char *first, unsigned int len1,
		char *sec, unsigned int len2,
		char *sum, unsigned int lsum
)
{
	unsigned int digit1, digit2, power, product;

	for (digit1 = len1 - 1; digit1 != _INT_MAX; digit1--)
	{
		for (digit2 = len2 - 1; digit2 != _INT_MAX; digit2--)
		{
			product = (first[digit1] - '0') * (sec[digit2] - '0');
			power = (len1 - digit1) + (len2 - digit2) - 2;
			add_em(sum, product, power, lsum);
		}
	}
	print_int(sum);
	_putchar('\n');
}

/**
 * err_prnt - Print error message and return error code
 */
void err_prnt(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * main - main function
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: 98 if an arg isn't numeric or !=2 ,otherwise 0
 */
int main(int argc, char *argv[])
{
	char *sum;
	unsigned int i, len1, len2, lens;

	if (argc != 3)
		err_prnt();
	len1 = isnumeric(argv[1]);
	if (len1 == 0)
		err_prnt();
	len2 = isnumeric(argv[2]);
	if (len2 == 0)
		err_prnt();
	lens = len1 + len2;
	sum = malloc(lens + 1);
	if (sum == NULL)
		err_prnt();
	sum[lens] = '\0';
	for (i = 0; i < lens; i++)
		sum[i] = '0';
	mult(
			argv[1], len1,
			argv[2], len2,
			sum, lens
	);
	free(sum);
	return (0);
}
