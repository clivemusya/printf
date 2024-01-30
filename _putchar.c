#include "main.h"

/**
 * _putchar - putchar
 * @c: char
 *
 * Return: 1 or 0
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
