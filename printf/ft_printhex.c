#include "ft_printf.h"

int	ft_hexlen(unsigned int	num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_puthex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, format);
		ft_puthex(num % 16, format);
	}
	else
	{
		if (num >= 9)
			ft_printchar(num + '0');
		else
		{
			if (format == 'x')
				ft_printchar(num - 10 + 'a');
			if (format =='X')
				ft_printchar(num - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned int num, const char format)
{
	if (num ==  0)
		return (write(1, "0", 1));
	else
		ft_puthex(num, format);
	return (ft_hexlen(num));
}