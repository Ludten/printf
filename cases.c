#include "main.h"

/**
 * c - print character
 *
 * @str: string buffer
 * @args: variadic list
 * @flags: flags
 * @field_width: field width
 */
void c(char **str, va_list args, int *flags, int *field_width)
{
	char s;

	s = (unsigned char)va_arg(args, int);
	if (!s)
	{
		*((*str)++) = '\0';
	}
	else
	{
		if (!(*flags & LEFT))
		{
			while (--*field_width > 0)
				*((*str)++) = ' ';
		}
		*((*str)++) = s;
		while (--*field_width > 0)
			*((*str)++) = ' ';
	}
}

/**
 * s - print string
 *
 * @str: string buffer
 * @args: variadic list
 * @flags: flags
 * @field_width: field width
 * @precision: precision
 * @len: string length
 */
void s(char **str, va_list args, int *flags,
int *field_width, int *precision, int *len)
{
	int i;
	const char *s, *b;

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
		*len = _strnlen(s, *precision);

		if (!(*flags & LEFT))
		{
			while (*len < (*field_width)--)
				*((*str)++) = ' ';
		}
		for (i = 0; i < *len; i++)
			*((*str)++) = *s++;
		while (*len < (*field_width)--)
			*((*str)++) = ' ';
	}
}

/**
 * p - print address
 *
 * @str: string buffer
 * @args: variadic list
 * @flags: flags
 * @field_width: field width
 * @precision: precision
 */
void p(char **str, va_list args, int *field_width, int *flags, int *precision)
{
	unsigned long s;
	const char *b;

	s = va_arg(args, unsigned long);
	if (!s)
	{
		b = "(nil)";

		while (*b)
		{
			*((*str)++) = *b++;
		}
	}
	else
	{
		if (*field_width == -1)
		{
			*field_width = sizeof(s);
			/* *flags |= ZEROPAD; */
			*flags |= SMALL;
			*flags |= SPECIAL;
		}
		*str = number(*str, s, 16, *field_width, *precision, *flags);
	}
}

/**
 * lh - length indicators
 *
 * @args: string buffer
 * @flags: flags
 * @qualifier: length specifier
 * @num: integer
 */
void lh(va_list args, int *flags, int *qualifier, unsigned long *num)
{
	if (*qualifier == 'l')
	{
		*num = va_arg(args, unsigned long);
	}
	else if (*qualifier == 'h')
	{
		*num = (unsigned short)va_arg(args, int);
		if (*flags & SIGN)
			*num = (short)*num;
	}
	else if (*flags & SIGN)
	{
		*num = va_arg(args, int);
	}
	else
	{
		*num = va_arg(args, unsigned int);
	}
}

/**
 * customspecifiers1 - assign functions to indicators
 *
 * @fmt: format
 * @str: string buffer
 * @args: variadic list
 * @flags: flags
 * @field_width: field width
 * @precision: precision
 * @len: length
 * Return: int
 */
int customspecifiers1(const char **fmt, char **str, va_list args, int *flags,
		     int *field_width, int *precision, int *len)
{
	switch (**fmt)
	{
	case 'c':
		c(str, args, flags, field_width);
		return (1);
	case 's':
		s(str, args, flags, field_width, precision, len);
		return (1);
	case 'r':
		r(str, args, flags, field_width, precision, len);
		return (1);
	case 'R':
		R(str, args, flags, field_width, precision, len);
		return (1);
	case 'S':
		S(str, args, flags, field_width, precision, len);
		return (1);
	case 'p':
		p(str, args, field_width, flags, precision);
		return (1);
	case '%':
		*((*str)++) = '%';
		return (1);
	default:
		return (0);
	}
}

