/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:50:49 by malton            #+#    #+#             */
/*   Updated: 2021/10/28 20:48:47 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		counter;
	int		result;
	va_list	arglist;

	if (!s)
		return (0);
	va_start(arglist, s);
	result = 0;
	counter = -1;
	while (s[++counter])
	{
		if (s[counter] == '%')
		{
			result += main_sorter(arglist, s[counter + 1]);
			counter++;
		}
		else
			result += ft_putchar(s[counter]);
	}
	va_end(arglist);
	return (result);
}
