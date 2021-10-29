/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:01:55 by malton            #+#    #+#             */
/*   Updated: 2021/10/28 20:50:13 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putunsigned_num(unsigned int n);
int		ft_strlen(char *string);
int		ft_putbase(unsigned int n, unsigned int base_length,
			char *base, int result);
int		ft_putLongBase(unsigned long int i, unsigned long int base_length,
			char *base, int result);
int		ft_putpointer(void *p);
int		main_sorter(va_list arglist, char c);
char	*ft_itoa(int n);

#endif
