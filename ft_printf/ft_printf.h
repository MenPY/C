#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>	
#include <stddef.h>
 # define CONVERSIONS 	"cspdiouxX"

typedef unsigned long long int t_size;

typedef struct			s_struct
{
	int c;

	int		has_precision;
	int 	has_width;
	int 	has_zero;
	int 	has_minus;
	int 	has_asterisk;
	int 	has_prec_asterisk;

	int		precision;
	int 	width;
}t_struct;

int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void 	ft_putstrlen(char *str, int len);
size_t	ft_strlen(const char *str);;
void	ft_putnbr_base(t_size nbr, char *base);
void	change_base(t_size nbr, char *base, t_size i);
int 	if_int(t_struct *args, va_list arg);
int 	if_uint(t_struct *args, va_list arg);
int 	if_ptr(t_struct *args, va_list arg);
int 	if_hex(t_struct *args, va_list arg);
int 	if_str(t_struct *args, va_list arg);
int		if_char(t_struct *args, va_list arg);
int 	put_int(int i, int padding);
int 	put_uint(unsigned int i, int padding);
int 	put_hex(unsigned int i, int padding, t_struct *args);
int 	get_digits(t_size n);
int	 	get_uint_digits(unsigned int n);
int		ft_isdigit(int c);
char 	*ft_strchr(char *str, char c);
int		ft_atoi(const char *str);
int get_hex_digits(unsigned int n, char *base);