/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:28:37 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/05 16:23:38 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	str_is_digit(char *input)
{
	while (input && *input)
	{
		if ((*input >= '0' && *input <= '9') || *input == ' ' || *input == '-')
			input++;
		else
			return (0);
	}
	return (1);
}

int	single_input_is_valid(char *input)
{
	char	**split_input;

	if (!str_is_digit(input))
		return (0);
	split_input = ft_split(input, ' ');
	if (!split_input)
		return (0);
	if (!check_valid_ints(split_input))
		return (0);
	return (1);
}

int	multi_input_is_valid(int elems, char **input)
{
	int	i;

	i = 0;
	if (!check_valid_ints(input))
		return (0);
	while (i < elems - 1)
	{
		if (!str_is_digit(input[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
