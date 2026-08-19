/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:25:58 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/19 14:02:39 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

//ft_printf
int	ft_printf(const char *format, ...);

// utils
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nb);
int	ft_putnbr_un(unsigned int n);
int	ft_puthex(unsigned long n, const char *base);

// specifiers
int	print_c(va_list args);
int	print_s(va_list args);
int	print_p(va_list args);
int	print_d(va_list args);
int	print_i(va_list args);
int	print_u(va_list args);
int	print_x(va_list args);
int	print_x_upper(va_list args);

#endif
