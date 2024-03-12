/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:28:37 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/12 10:52:13 by gachalif         ###   ########.fr       */
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

int	check_duplicates(char **input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		j = i;
		while (input[j])
		{
			if (i != j)
				if (ft_atoi(input[i]) == ft_atoi(input[j]))
					return (1);
			j++;
		}
		i++;
	}
	return (0);
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
	return (check_duplicates(split_input) == 0);
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
	return (check_duplicates(input + 1) == 0);
}
