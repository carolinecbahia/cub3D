/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_safe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccavalca <ccavalca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 22:24:16 by ccavalca          #+#    #+#             */
/*   Updated: 2026/08/01 14:14:04 by ccavalca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>

/*converts string to int with validation and overflow checking.*/

static int	convert_sign(const char **str)
{
	int	sign;

	sign = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

int	ft_atoi_safe(const char *str, int *out)
{
	long	nb;
	int		sign;

	if (!str || !out)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = convert_sign(&str);
	if (!ft_isdigit(*str))
		return (0);
	nb = 0;
	while (ft_isdigit(*str))
	{
		nb = (nb * 10) + (*str - '0');
		if ((sign == 1 && nb > INT_MAX) || (sign == -1 && (-1 * nb) < INT_MIN))
			return (0);
		str++;
	}
	while (ft_isspace(*str))
		str++;
	if (*str != '\0')
		return (0);
	*out = (int)(nb * sign);
	return (1);
}
