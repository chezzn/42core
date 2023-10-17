/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:19:35 by zichen            #+#    #+#             */
/*   Updated: 2023/10/11 16:19:37 by zichen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int				p;
	unsigned int	nb;
	char			*str;

	nb = (unsigned int)n;
	p = ft_numbersize(nb, n);
	str = (char *)malloc(sizeof(char) * (p + 1));
	if (str == NULL)
		return (NULL);
	if (isneg(n))
		nb = -nb;
	str[0] = '-';
	str[p] = '\0';
	i = p - 1;
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

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_printstr(num);
	free (num);
	return (len);
}
