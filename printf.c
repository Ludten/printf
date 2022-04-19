#include "main.h"

/**
 * _vsprintf - analysis all incoming parameters
 *
 * @buf: buffer
 * @fmt: format
 * @args: vardiac list
 * Return: int
 */
int _vsprintf(char *buf, const char *fmt, va_list args)
{
	int len, result = 0, base = 10;
	unsigned long num;
	char *str;
	int flags, field_width, precision, qualifier;
	/* 'h', 'l'for integer fields */
	for (str = buf; *fmt; ++fmt)
	{
		if (*fmt != '%')
		{
			*str++ = *fmt;
			continue;
		}
		/* process flags */
		getflags(&fmt, &flags);

		/* get field width */
		getwidth(&fmt, args, &field_width, &flags);
		/* get the precision */
		getprecision(&fmt, args, &precision);
		/* get the conversion qualifier */
		getqualifier(&fmt, &qualifier);
		result = customspecifiers1(&fmt, &str, args, &flags,
				&field_width, &precision, &len);
		if (result)
			continue;
		result = customspecifiers2(&fmt, &str, &flags, &base);
		if (result)
			continue;
		lh(args, &flags, &qualifier, &num);
		str = number(str, num, base, field_width, precision, flags);
	}
	*str = '\0';
	return (str - buf);
}

/**
 * _printf - printf
 *
 * @format: format
 * @...: arguments
 * Return: int
 */
int _printf(const char *format, ...)
{
	char printf_buf[1024];
	va_list args;
	int printed;

	if (format == NULL || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	va_start(args, format);
	printed = _vsprintf(printf_buf, format, args);
	va_end(args);
	_puts(printf_buf);
	return (printed);
}
