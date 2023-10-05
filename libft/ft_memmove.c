/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:54:46 by zichen            #+#    #+#             */
/*   Updated: 2023/09/20 12:41:54 by zichen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	d = (char *)dest;
	s = (char *)src;
	if (dest == src)
		return (dest);
	if (dest > src)
	{
		i = (int)(n - 1) + 1;
		while (--i >= 0)
			*(d + i) = *(s + i);
	}
	else
	{
		i = -1;
		while (++i < (int)n)
			*(d + i) = *(s + i);
	}
	return (dest);
}
