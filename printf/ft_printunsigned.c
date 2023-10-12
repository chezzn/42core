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

int	ft_numlen(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 10;
	}
	return (len);
}

char	*ft_unsigneditoa(unsigned int n)
{
	int		len;
	char	*num;

	len = ft_numlen(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (num == NULL)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		if (n < 10)
			num[len - 1] = n - '0';
		num[len - 1] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_printunsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		write(1, "0", 1);
	else
	{
		num = ft_unsigneditoa(n);
		len += ft_printstr(num);
		free(num);
	}
	return (len);
}
