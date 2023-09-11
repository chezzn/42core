/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 11:54:46 by zichen            #+#    #+#             */
/*   Updated: 2023/09/10 12:26:44 by zichen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t len;

	len = 0;
	if (dest < src)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *)dest)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			len++;
			((unsigned char *)dest)[len] = ((unsigned char *)src[len];
		}
	}
	return (dest);
}
