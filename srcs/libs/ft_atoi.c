/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:35:27 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 09:35:27 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	bank;
	int	sign;

	bank = 0;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		sign += (-2 * (*nptr == '-'));
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		bank *= 10;
		bank += sign * (*nptr - 48);
		nptr++;
	}
	return (bank);
}

int	fits_in_int(const char *nptr)
{
	long	bank;
	long	sign;

	bank = 0;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		sign += (-2 * (*nptr == '-'));
		nptr++;
	}
	if (ft_strlen(nptr) > 10)
		return (0);
	while (ft_isdigit(*nptr))
	{
		bank *= 10;
		bank += sign * (*nptr - 48);
		nptr++;
	}
	return ((bank <= 2147483647 && bank >= -2147483648));
}

int	check_valid_ints(char **split_input)
{
	char	*str;

	split_input++;
	while (*split_input)
	{
		str = *split_input;
		if (!fits_in_int(str))
			return (0);
		if (*str == '-')
			str++;
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (0);
			str++;
		}
		split_input++;
	}
	return (1);
}
