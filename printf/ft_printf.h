/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zichen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:19:37 by zichen            #+#    #+#             */
/*   Updated: 2023/10/09 19:19:39 by zichen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_conversions(va_list args, const char format);
int	ft_printchar(int c);
int	ft_printnbr(int n);
int	ft_printstr(char *str);
int	ft_printhex(unsigned int num, const char format);
int	ft_printunsigned(unsigned int n);
int	ft_printptr(unsigned long long ptr);
int	ft_printpercent(int c);

#endif
