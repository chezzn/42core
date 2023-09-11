/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:04:57 by zichen            #+#    #+#             */
/*   Updated: 2023/09/10 17:17:48 by zichen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_stnstr(const char *big, const char *little, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little == NULL || little[0] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < n)
	{
		if (big[i] == little[j])
		{
			while (big[i + j] == little[j] && (i + j) < n)
			{
				if (little[j + 1] == '\0')
					return ((char *)big + i);
				j++;
			}
			j = 0;
		}
		i = 0;
	}
	return (NULL);
}
