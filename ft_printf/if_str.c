#include "ft_printf.h"

int if_str(t_struct *args, va_list arg)
{
    int width;
    int precision;
    int len;
    int real_len;
    char *str;

    width = args->has_width ? args->width : 0;
    precision = args->has_precision ? args->precision : 0;
    if(args->has_asterisk)
        width = va_arg(arg, int);
       
    if(args->has_prec_asterisk)
        precision = va_arg(arg, int);
    str = va_arg(arg, char *); 

    if (!str)
        str = "(null)";

    len = ft_strlen(str);
    if(args->has_precision)
        real_len = (len > precision) ? precision : len;
    else
        real_len = len;
    if (args->has_minus)
    {
        ft_putstrlen(str, real_len);

        while((width - real_len) > 0)
        {
            ft_putchar(' ');
            width--;
        }
    }
    else
    {  
        while((width - real_len) > 0)
        {
            ft_putchar(' ');
             width--;
        }
        ft_putstrlen(str, real_len);
    }
    return (0);
}