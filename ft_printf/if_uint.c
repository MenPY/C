#include "ft_printf.h"
int get_uint_digits(unsigned int n)
{
	int digits;
	digits = 0;

	while(n / 10)
	{
		digits++;
		n /= 10;
	}
	digits++;
	return (digits);
}

int put_uint(unsigned int i, int padding)
{
    while(padding-- > 0)
        ft_putchar('0');
    ft_putnbr_base(i, "0123456789");
    return (0);
}

int if_uint(t_struct *args, va_list arg)
{
    int i;
    int width;
    int precision;
    int len;
    int real_len;
    int padding;

    if(args->has_precision)
        args->has_zero = 0;
 
    width = args->has_width ? args->width : 0;
    precision = args->has_precision ? args->precision : 0;
    if(args->has_asterisk)
        width = va_arg(arg, int);
       
    if(args->has_prec_asterisk)
        precision = va_arg(arg, int);
    i = (unsigned int)va_arg(arg, unsigned int); 
    len = get_uint_digits(i);
    padding = (len < precision) ? precision - len : 0;
    real_len = len + padding;

    if (args->has_minus && !(args->has_zero))
    {
        if(i != 0)
        put_uint(i, padding);

        while ((width - real_len > 0))
        {
            ft_putchar(' ');
            width--;
        }
    }
    else if (args->has_zero && !(args->has_minus))
    {
        put_uint(i, width - len);
    }
    else if (args->has_zero && args->has_minus)
    {
        real_len = len;
        padding = 0;
        if(i != 0)
            put_uint(i, padding);
        while ((width - real_len > 0))
        {
            ft_putchar(' ');
            width--;
        }
    }
    else
    {
        while ((width - real_len > 0))
        {
            ft_putchar(' ');
            width--;
        }
        if(i != 0)
            put_uint(i, padding);
    }
    return (real_len);
}