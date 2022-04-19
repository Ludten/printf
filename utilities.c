#include "main.h"

/**
 * getflags - check for flags
 *
 * @fmt: format
 * @flags: flags
 */
void getflags(const char **fmt, int *flags)
{
	*flags = 0;

repeat:
	++(*fmt);          /* this also skips first '%' */
	switch (**fmt)
	{
	case '-':
		*flags |= LEFT;
		goto repeat;
	case '+':
		*flags |= PLUS;
		goto repeat;
	case ' ':
		*flags |= SPACE;
		goto repeat;
	case '#':
		*flags |= SPECIAL;
		goto repeat;
	case '0':
		*flags |= ZEROPAD;
		goto repeat;
	}
}

/**
 * getwidth - check for width value
 *
 * @fmt: format
 * @args: variadic list
 * @field_width: field width
 * @flags: flags
 */
void getwidth(const char **fmt, va_list args, int *field_width, int *flags)
{
	*field_width = -1;
	if (_isdigit(**fmt))
	{
		*field_width = skip_atoi(fmt);
	}
	else if (**fmt == '*')
	{
		++(*fmt);
		/* it is the next argument */
		*field_width = va_arg(args, int);
		if (*field_width < 0)
		{
			*field_width = -(*field_width);
			*flags |= LEFT;
		}
	}
}

/**
 * getprecision - check for precision indicator
 *
 * @fmt: format
 * @args: variadic list
 * @precision: precision
 */
void getprecision(const char **fmt, va_list args, int *precision)
{
	*precision = -1;
	if (**fmt == '.')
	{
		++(*fmt);
		if (_isdigit(**fmt))
		{
			*precision = skip_atoi(fmt);
		}
		else if (**fmt == '*')
		{
			++(*fmt);
			/* it is the next argument */
			*precision = va_arg(args, int);
		}
		if (*precision < 0)
			*precision = 0;
	}
}

/**
 * getqualifier - check for length indicator
 *
 * @fmt: format
 * @qualifier: length
 */
void getqualifier(const char **fmt, int *qualifier)
{
	*qualifier = -1;
	if (**fmt == 'h' || **fmt == 'l')
	{
		*qualifier = **fmt;
		++(*fmt);
	}
}
