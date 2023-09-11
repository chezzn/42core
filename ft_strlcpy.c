/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:31:19 by zichen            #+#    #+#             */
/*   Updated: 2023/09/10 13:08:53 by zichen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0) // calculate length of source string
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0') // copies characters from src to dest
	{
		dest[i] = src[i];
		i++;
	}
	if (i < size) // add null terminator if i < size
		dest[i] = '\0';
	while (src[i] != '\0') // determine total length of src
		i++;
	return (i);
}
