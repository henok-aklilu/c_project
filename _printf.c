#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, count = 0;
	char c, *s;

	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *);
				if (s == NULL)
				{
					s = "(null)";
					write(1, s, 6);
					count += 6;
				}
				else
				{
					write(1, s, strlen(s) + 1);
					count += strlen(s);
				}
			}
			else
			{
				write(1, &format[i], 1);
				count++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}

int main(void)
{
	_printf(" %c", _printf("H%c", 'A') + 48);

	return (0);
}


