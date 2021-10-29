/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 01:27:01 by malton            #+#    #+#             */
/*   Updated: 2021/10/28 20:58:00 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_strlen(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	*string;
	int		res;

	string = ft_itoa(n);
	res = ft_putstr(string);
	free(string);
	return (res);
}

int	ft_putunsigned_num(unsigned int n)
{
	char	*string;
	int		res;

	string = ft_itoa(n);
	res = ft_putstr(string);
	free(string);
	return (res);
}

int	ft_putbase(unsigned int n, unsigned int base_length, char *base, int result)
{    
	if (n >= base_length)
	{
		result = ft_putbase(n / base_length, base_length, base, result);
		ft_putbase(n % base_length, base_length, base, result);
		return (result + 1);
	}
	return (result + ft_putchar(base[n]));
}


int    ft_put_long_base(unsigned long int n, unsigned long int base_length, char *base, int result)
{
    if (n >= base_length)
	{
		result = ft_put_long_base(n / base_length, base_length, base, result);
		ft_put_long_base(n % base_length, base_length, base, result);
		return (result + 1);
	}
	return (result + ft_putchar(base[n]));
}

int	ft_putpointer(void *p)
{
	return (ft_putstr("0x") + ft_put_long_base((unsigned long int)p, ft_strlen("0123456789abcdef"), "0123456789abcdef", 0));
}

int	main_sorter(va_list arglist, char c)
{
	if (c == 's')
		return (ft_putstr(va_arg(arglist, char *)));
	if (c == 'c')
		return (ft_putchar((char)va_arg(arglist, int)));
	if (c == 'i' || c == 'd' )
		return (ft_putnbr((va_arg(arglist, int))));
	if (c == '%')
		return (ft_putchar('%'));
	if (c == 'u')
		return (ft_putbase(va_arg(arglist, unsigned int), ft_strlen("0123456789"), "0123456789", 0));
	if (c == 'p')
		return (ft_putpointer(va_arg(arglist, void *)));
	if (c == 'x')
		return  (ft_putbase(va_arg(arglist, int), ft_strlen("0123456789abcdef"), "0123456789abcdef", 0));
	if (c == 'X')
		return (ft_putbase(va_arg(arglist, int), ft_strlen("0123456789ABCDEF"), "0123456789ABCDEF", 0));
	return (0);
}
