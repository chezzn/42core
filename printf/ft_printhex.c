/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:53:02 by zichen            #+#    #+#             */
/*   Updated: 2023/10/12 16:53:05 by zichen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_puthex(num / 16, format);
		ft_puthex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_printchar(num + '0');
		else
		{
			if (format == 'x')
				ft_printchar(num - 10 + 'a');
			if (format == 'X')
				ft_printchar(num - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned int num, const char format)
{
	int	len;

	len = 0;
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(num, format);
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}
