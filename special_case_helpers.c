#include "main.h"

/**
 * hex - convert special chars to hexadecimal
 * @s: pointer to char
 *
 * Return: pointer to converted string
 */

char *hex(char s)
{
	int r, i = 3;
	char *p = malloc(5 * sizeof(char));

	while (s)
	{
		r = s % 16;
		p[i--] = (r >= 0 && r <= 9) ? '0' + r : 'A' + (r - 10);
		s /= 16;
		if (s == 0)
		{
			p[i] = '0';
			break;
		}
	}
	p[0] = '\\', p[1] = 'x', p[4] = '\0';
	return (p);
}

/**
 * transform - transform string
 * @str: pointer to a const string
 *
 * Return: pointer to a transformed string
 */

char *transform(const char *str)
{
	char *p, *ch, *r;
	int i = 0, j = 0, len = 0;

	while (str[i])
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
			len += 4;
		else
			len += 1;
		i++;
	}
	p = malloc((len + 1) * sizeof(*p));
	i = 0;
	while (str[i])
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			ch = hex(str[i]);
			r = ch;
			while (*ch)
			{
				p[j++] = *ch++;
			}
			free(r);
		}
		else
		{
			p[j++] = str[i];
		}
		i++;
	}
	p[j] = '\0';
	return (p);
}

/**
 * S - transform and print string
 *
 * @str: string buffer
 * @args: variadic list
 * @flags: flags
 * @field_width: field width
 * @precision: precision
 * @len: string length
 */
void S(char **str, va_list args, int *flags,
int *field_width, int *precision, int *len)
{
	int i;
	const char *s, *b;
	char *buff, *r;

	s = va_arg(args, char *);
	if (!s)
	{
		b = "(null)";

		while (*b)
		{
			*((*str)++) = *b++;
		}
	}
	else
	{
		buff = transform(s);
		r = buff;
		*len = _strnlen(buff, *precision);

		if (!(*flags & LEFT))
		{
			while (*len < (*field_width)--)
				*((*str)++) = ' ';
		}
		for (i = 0; i < *len; i++)
			*((*str)++) = *buff++;
		while (*len < (*field_width)--)
			*((*str)++) = ' ';
		free(r);
	}
}

