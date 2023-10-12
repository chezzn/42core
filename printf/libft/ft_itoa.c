/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:41:22 by zichen            #+#    #+#             */
/*   Updated: 2023/09/25 11:41:33 by zichen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	isneg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static	int	ft_numbersize(unsigned int nb, int n)
{
	int	temp;
	int	len;

	len = 0;
	if (nb == 0)
		len = 1;
	if (isneg(n) == 1)
		len++;
	temp = n;
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int				i;
	int				len;
	unsigned int	nb;
	char			*str;

	nb = (unsigned int)n;
	len = ft_numbersize(nb, n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	if (isneg(n))
		nb = -nb;
	str[0] = '-';
	str[len] = '\0';
	i = len - 1;
	if (nb == 0)
		str[i] = '0';
	while (nb && nb != 0)
	{
		if (nb < 10)
			str[i] = nb - '0';
		str[i--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}
