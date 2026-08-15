/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:24:57 by ccavalca          #+#    #+#             */
/*   Updated: 2026/04/14 22:45:46 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>
#include <stdio.h>

/*prints formatted output to the given file descriptor.*/

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args;
	int		ret;

	if (!format)
		return (-1);
	va_start(args, format);
	ret = vdprintf(fd, format, args);
	va_end(args);
	return (ret);
}
