#include <stdarg.h>
#include <string.h>
#include "main.h"

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
char c, *s;

unsigned int num_chars_printed = 0;
while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
c = va_arg(args, int);
_putchar(c);
num_chars_printed++;
}
else if (*format == 's')
{
*s = va_arg(args, char *);
fputs(s, stdout);
num_chars_printed += strlen(s);
}
else if (*format == '%')
{
_putchar('%');
num_chars_printed++;
}
}
else
{
_putchar(*format);
num_chars_printed++;
}
format++;
}

va_end(args);

return (num_chars_printed);
}
