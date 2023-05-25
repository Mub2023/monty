#include "monty.h"
/**
 * Gint - gets a chars pointers to new string contains int.
 * @num: number to convert.
 * Return: the char pointer to new created string,or NULL.
 */
char *Gint(int num)
{
	unsigned int t;
	int len = 0;
	long num_1 = 0;
	char *R;

	t = _abs(num);
	len = get_num_len(t, 10);

	if (num < 0 || num_1 < 0)
		len++;
	R = malloc(len + 1);
	if (!R)
		return (NULL);
	fill_num_buff(t, 10, R, len);
	if (num < 0 || num_1 < 0)
		R[0] = '-';

	return (R);
}
/**
 * _abs - gets the absolute of value of an integer.
 * @x: intger to get absolute vale of .
 * Return: unsigned int abs of x.
 */
unsigned int _abs(int x)
{
	if (x < 0)
		return (-(unsigned int)x);
	return ((unsigned int)x);
}
/**
 * get_num_len - gets length of numbers needed for unsigned int.
 * @num: number to get length of .
 * @base: base of number to representations used by buffer.
 * Return: intger contains length.
 */
int get_num_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
/**
 * fill_num_buff - fills buffer with correct numbers up to base 36.
 * @num: an input int.
 * @base: is base number used to convert.
 * @buff: buffer to fill with result of convertion.
 * @buff_size: size of the buffer.
 * Retrun: Always 0 (SUCCESS).
 */
void fill_num_buff(unsigned int num, unsigned int base,
		char *buff, int buff_size)
{
	int R, x = buff_size - 1;

	buff[buff_size] = '\0';
	while (x >= 0)
	{
		R = num % base;
		if (R > 9)
			buff[x] = R + 87;
		else
			buff[x] = R + '0';
		num /= base;
		x--;
	}
}
