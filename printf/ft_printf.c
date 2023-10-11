/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:19:25 by zichen            #+#    #+#             */
/*   Updated: 2023/10/09 19:19:27 by zichen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversions(va_list args, const char format)
{
	int	len;

	len = 0;
	if  (format == 'c')
		len += ft_printchar(va_arg(args, int));
	else if  (format == 's')
		len += ft_printstr(va_arg(args, char *));
	else if  (format == 'p')
		len += ft_printptr(va_arg(args, unsigned long));
	else if  ((format == 'd') || else if  (format == 'i'))
		len += ft_printnbr(va_arg(args, int));
	else if  (format == 'u')
		len += ft_printunsigned(va_arg(args, unsigned int));
	else if  ((format == 'x') || (format == 'X'))
		len += ft_printhex(va_arg(args, unsigned int));
	else
		write(1, &format, 1);
	return (len);
}

int	ft_printf(const char *, ...)
{

}
