/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:35:42 by zichen            #+#    #+#             */
/*   Updated: 2023/09/23 18:35:44 by zichen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	ft_numbersize(int nb)
{
	unsigned int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len += 1;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	number;
	unsigned int	length;

	length = ft_numbersize(n);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		number = -n;
	}
	else
		number = n;
//	if (number == 0)
//		str[0] == '0';
	str[length] = '\0';
	while (number != 0)
	{
		str[length - 1] = (number % 10) + '0';
		number = number / 10;
		length--;
	}
	return (str);
}
