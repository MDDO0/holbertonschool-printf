#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: The character to write
 *
 * Return: 1 (Success), -1 (Error)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
