#include <stdio.h>
#include "ft_printf.h"

int	main()
{
	char	c;
	char	*str;
	int	d;

	c = 'a';
	str = "lola";
	d = '9';

	ft_printf("%c", c);
	printf("%c", c);
}
