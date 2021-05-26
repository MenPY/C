#include "ft_printf.h"

int get_digits(t_size n)
{
    long a;
    a = n;
	int digits;
	digits = 0;

	if (a < 0)
	{
		digits++;
		a *= -1;
	}
	while(a / 10)
	{
		digits++;
		a /= 10;
	}
	digits++;
	return (digits);
}

int put_int(int i, int padding)
{
    if (i == -2147483648)
    {
        ft_putchar('-');
        while (padding-- > 0)
            ft_putchar('0');
        ft_putstr("2147483648");
        return (0);
    }
    if (i < 0)
    {
        ft_putchar('-');
        i *= -1;
    }
    while(padding-- > 0)
        ft_putchar('0');
    ft_putnbr_base(i, "0123456789");
    return (0);
}

int if_int(t_struct *args, va_list arg)
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
    i = va_arg(arg, int); 
    len = get_digits(i);
    if (i < 0) 
	    padding = ((len - 1) < precision) ? precision - (len - 1) : 0;
    else
        padding = (len < precision) ? precision - len : 0;

    real_len = len + padding;
    if (args->has_minus && !(args->has_zero))
    {
        if(i != 0)
        put_int(i, padding);

        while ((width - real_len > 0))
        {
            ft_putchar(' ');
            width--;
        }
    }
    else if (args->has_zero && !(args->has_minus))
        put_int(i, width - len);
    else if (args->has_zero && args->has_minus)
    {
        real_len = len;
        padding = 0;
        if(i != 0)
            put_int(i, padding);
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
            put_int(i, padding);
    }
    return (real_len);
}