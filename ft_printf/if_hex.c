#include "ft_printf.h"

int get_hex_digits(unsigned int n, char *base)
{

    long int quotient;
	int i=1,j,temp;
	//char hexadecimalNumber[100];
	int count = 0;
	quotient = n;
	while(quotient!=0) 
    {
		temp = quotient % 16;
		//To convert integer into character
		if(temp < 10)
		    temp =temp + 48;
         else
		    temp = temp + 55;

		//hexadecimalNumber[i++]= temp;
		quotient = quotient / 16;
        count++;
    }
    //printf("%d", count);
    return (count);
    /*int count = 0;
    if (n < 0)
	{
		//ft_putchar('-');
		n *= -1;
	}
	else if (n > 16 - 1)
	{
		get_hex_digits(n / 16, base);
		get_hex_digits(n % 16, base);
	}
	if (n < 16)
        count++;
		//ft_putchar(base[n]);

    printf("[%d]", count);
    return (count);
    */

}

int put_hex(unsigned int i, int padding, t_struct *args)
{
   // printf("PADDING IS %d", padding);
     while(padding-- > 0)
        ft_putchar('0');
    if(args->c == 'x')
        ft_putnbr_base(i, "0123456789abcdef");
    else if(args->c == 'X')
        ft_putnbr_base(i, "0123456789ABCDEF");
    return (0);
    //printf("lol");
}

int if_hex(t_struct *args, va_list arg)
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
    len = (i == 0) ? 1 : get_hex_digits(i, "0123456789abcdef");

    //printf("\n%d", len);
    padding = (len < precision) ? precision - len: 0;
    real_len =  len + padding;
    //printf("len %d\n", len);
   // printf("width %d\n", width);
    //printf("real len%d\n", real_len);
    if (args->has_minus && !(args->has_zero))
    {
        //if(i != 0)
        put_hex(i, padding, args);

        while ((width - real_len > 0))
        {
            ft_putchar(' ');
            width--;
        }
    }
    else if (args->has_zero && !(args->has_minus))
    {
        put_hex(i, width - len, args);
    }
    else if (args->has_zero && args->has_minus)
    {
        real_len = len;
        padding = 0;
        if(i != 0)
            put_hex(i, padding, args);
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
        //if(i != 0)
            put_hex(i, padding, args);
    }
    return (real_len);
}