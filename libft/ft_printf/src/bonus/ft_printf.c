/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:02:10 by ccavalca          #+#    #+#             */
/*   Updated: 2025/08/14 21:01:07 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	which_specifier(char specifier, va_list args)
{
	if (specifier == 'c')
		return (print_c(args));
	else if (specifier == 's')
		return (print_s(args));
	else if (specifier == 'p')
		return (print_p(args));
	else if (specifier == 'd')
		return (print_d(args));
	else if (specifier == 'i')
		return (print_i(args));
	else if (specifier == 'u')
		return (print_u(args));
	else if (specifier == 'x')
		return (print_x(args));
	else if (specifier == 'X')
		return (print_x_upper(args));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *print, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, print);
	i = 0;
	count = 0;
	while (print[i])
	{
		if (print[i] == '%' && print[i + 1] != '\0')
		{
			i++;
			count += which_specifier(print[i], args);
		}
		else
		{
			count += ft_putchar(print[i]);
		}
		i++;
	}
	va_end(args);
	return (count);
}
