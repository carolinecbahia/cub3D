/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 19:11:17 by ccavalca          #+#    #+#             */
/*   Updated: 2025/08/14 20:54:59 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	return (ft_putchar(c));
}

int	print_s(va_list args)
{
	char	*s;

	s = va_arg(args, char *);
	if (!s)
		return (ft_putstr("(null)"));
	return (ft_putstr(s));
}

int	print_d(va_list args)
{
	int	n;

	n = va_arg(args, int);
	return (ft_putnbr(n));
}

int	print_i(va_list args)
{
	return (print_d(args));
}
