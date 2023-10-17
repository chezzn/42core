/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:52:06 by zichen            #+#    #+#             */
/*   Updated: 2023/10/12 16:52:08 by zichen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned long n)
{
	int		len;

	len = 0;
	if (n >= 10)
	{
		len += 1 + ft_printunsigned(n / 10);
		ft_printchar(n % 10 + '0');
	}
	else
		len += ft_printchar(n + '0');
	return (len);
}
