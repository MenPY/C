#include "ft_printf.h"


void init_struct(t_struct *args)
{
    args->c = 0;
    args->has_precision = 0;
    args->has_width = 0;
    args->has_zero = 0;
    args->has_minus = 0;
    args->has_asterisk = 0;
    args->has_prec_asterisk = 0;
    
    args->precision = 0;
    args->width = 0;
}

char *read_args(t_struct *args, char *str)
{
    if (!str || *str != '%')
        return (str);

  // str++; // !!!!!!!
    while(*str)
    {
        init_struct(args);

        if (*str == '-')
        {
            args->has_minus = 1;
            str++;
        }
        if (*str == '0')  
        {
            args->has_zero = 1;
            str++;
        }
        if (*str =='*') //ft_printf("%*.*d", 5, 3, 123);
        {
            args->has_asterisk = 1;
            str++;
        }
        if (ft_isdigit(*str))
        {
            
            args->has_width = 1;
            args->width = ft_atoi(str);  
            str += get_digits(args->width);
        }
        if (*str == '.')
        {
            args->has_precision = 1;
            str++;
        }
        if (*str =='*')
        {
            args->has_prec_asterisk = 1;
            str++;
        }
        
        else if  (ft_isdigit(*str))
        {
            args->has_precision = 1;
            args->precision = ft_atoi(str);
            str += get_digits(args->precision);
        }
        if (ft_strchr(CONVERSIONS, *str))
        {
            args->c = *str;
            str++;
            return (str);
        }
        str++;
    }
    return (str);
}

int put_convs(t_struct *args, va_list arg)
{
	if(args->c == 'c')
	    return (if_char(args, arg));
    else if(args->c == 'd' || args->c == 'i')
		return(if_int(args, arg));
    else if(args->c == 'p')
        return(if_ptr(args, arg));
    else if(args->c == 'u')	
        return (if_uint(args, arg));
    else if(args->c == 's')
        return (if_str(args, arg));
    else if(args->c == 'x' || args->c == 'X')				
        return (if_hex(args, arg));
    return 0;
} 

int	ft_printf(const char *format, ...)
{
    int count;
    char *str;
    str = (char *)format;
    t_struct args;
    count = 0;
    if (!str)
        return (0);
	va_list			arg;
	va_start(arg, format);
    while(*str)
    {
        if(*str == '%' && *str++ == '%')
            ft_putchar('%');

        while(*str != '%' && *str != '\0') 
		{ 
			ft_putchar(*str);
			str++; 
            ++count;
		}
    
        if(*str == '%')
        {
            str = read_args(&args, str);
            count += put_convs(&args, arg);
        }
        //if(*str == '%' && *str++ == '%')
           // ft_putchar('%');
    }
	va_end(arg);
	return (count);
}
 
int main()
{
    
    ft_printf("%% %d ab %%cd%%", 1);
    // int t;
	// char c;

	// c = 'a';
	// t = 50;
	// ft_printf("%d\n", -589);
    // ft_printf("%-4d\n", -2464);
    // ft_printf("%.5d\n", -2372);
	// ft_printf("%p\n", NULL);
	// ft_printf("%15p\n", NULL);
	// ft_printf("%-15p\n", NULL);
    // ft_printf("ret = %d\n", ft_printf("%%p::[%010d]\n", -8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%10d]\n", -8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%.5d]\n", -8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%01.1d]\n", -8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%010.1d]\n", -8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%01.50d]\n", -8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%1.50d]\n", -8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%0100.50d]\n", -8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%010d]\n", 8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%10d]\n", 8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%.5d]\n", 8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%01.1d]\n", 8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%010.1d]\n", 8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%01.50d]\n", 8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%1.50d]\n", 8473));
    // ft_printf("ret = %d\n", ft_printf("%%p::[%0100.50d]\n", 8473));
	// ft_printf("%c\n", 'a');
	// ft_printf("%10c\n", 't');
	// ft_printf("%1c\n", 'y');
	// ft_printf("%50.2s\n", "Coucou");
	// ft_printf("%50.2s\n", NULL);
	// ft_printf("%5.0s\n", "Hello");
	// ft_printf("%.1s\n", "Test");
	// ft_printf("%10s\n", NULL);
	// ft_printf("%10s\n", "Ok");
   
}

/*int main()
{
    //printf("alal");
    //int a = 100;
    //printf("%010%\n"); // !!!!!!!!!!!!!!!!! chi dzac
    //ft_printf("[%p\n]", NULL);
}*/