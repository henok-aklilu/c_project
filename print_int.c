#include "main.h"

/**
 * num_len - finds the length of a number.
 * @n: the number to find his length
 *
 * Return: the number of characters to print
 */
int num_len(int n)
{
	int i = 0;

	while (n != 0)
	{
		n /= 10;
		i++;
	}
	if (i == 0)
		return (0);
	else
		return (--i);
}
/**
 * pw - opt for the pow() function in math.h lib
 * @n: the base number
 * @p: the power
 * Return: n to the power of p
 */

int pw(int n, int p)
{
	int i = 0, r = 1;
	for (; i < p; i++)
		r = r * n;
	return (r);
}

/**
 * print_int - prints integer
 * @n: the number to print
 *
 * Return: the number of characters printed
 */
int print_int(int n)
{
	int i = 0, len = num_len(n), count = 0;
	unsigned int pow = 1, buffer = 0;
	char c;

	if (n < 0)
	{
		write(1, &"-", 1);
		buffer = (unsigned int)n * -1;
		count++;
	}
	else
		buffer = (unsigned int)n;

	for (i = len; i >= 0; i--)
	{
		pow = pw(10, i);

		c = (buffer / pow) + 48;
		buffer = buffer % pow;
		write(1, &c, 1);
		count++;
	}

	return (count);
}
