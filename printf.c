#include <stdarg.h>
#include <string.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    
    int num_chars_printed = 0;
    printf("%d", 5)
    while (*format != '\0') {
        if (*format == '%') {
            format++;
            if (*format == 'c') {
                char c = va_arg(args, int);
                _putchar(c);
                num_chars_printed++;
            } else if (*format == 's') {
                char *s = va_arg(args, char *);
                fputs(s, stdout);
                num_chars_printed += strlen(s);
            } else if (*format == '%') {
                _putchar('%');
                num_chars_printed++;
            }
        } else {
            _putchar(*format);
            num_chars_printed++;
        }
        format++;
    }
    
    va_end(args);
    
    return num_chars_printed;
}
