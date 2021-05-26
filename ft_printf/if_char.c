#include "ft_printf.h"

int if_char(t_struct *args, va_list arg)
{
    int     width;
    char    str;

    width = args->has_width ? args->width : 0;
    if(args->has_asterisk)
        width = va_arg(arg, int);
    str = va_arg(arg, int);
    if (!str)
        return (0);
    if (args->has_minus)
    {
        ft_putchar(str);
        while((width - 1) > 0)
        {
            ft_putchar(' ');
            width--;
        }
    }
    else
    {  
        while((width - 1) > 0)
        {
            ft_putchar(' ');
             width--;
        }
        ft_putchar(str);
    }
    return (0);
}