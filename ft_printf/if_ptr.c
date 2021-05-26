#include "ft_printf.h"

int put_ptr(t_size i)
{
    write(1, "0x", 2);
	ft_putnbr_base(i, "0123456789abcdef");
    return 0;
}

int if_ptr(t_struct *args, va_list arg)
{
    t_size i;
    int width;
    int precision;
    int len;
    int real_len;
    int padding;
    int x;
    

    if(args->has_precision)
        args->has_zero = 0;
 
    width = args->has_width ? args->width : 0;
    precision = args->has_precision ? args->precision : 0;
    if(args->has_asterisk)
        width = va_arg(arg, int);
       
    if(args->has_prec_asterisk)
        precision = va_arg(arg, int);
    i = (t_size)va_arg(arg, void *);  

    len = get_digits(i) - 1;

    if (i < 0) 
	    padding = ((len - 1) < precision) ? precision - (len - 1) : 0;
    else
        padding = (len < precision) ? precision - len : 0;

    real_len = width - len;
    if (args->has_minus)
    {
            if(!i)
              ft_putstr("0x0");
            else
               put_ptr(i);
        while ((width - len > 0))
        {
            ft_putchar(' ');
            width--;
        }
    }
    else
    {
        while ((width - len > 0))
        {
            ft_putchar(' ');
            width--;
        }
            if(!i)
              ft_putstr("0x0");
            else
               put_ptr(i);
    }
    return 0;
}