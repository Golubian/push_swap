/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:40:50 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/12 09:40:23 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_pos_in_stack(char **str_elems, int index)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str_elems[i])
	{
		if (i != index && ft_atoi(str_elems[i]) < ft_atoi(str_elems[index]))
			count++;
		i++;
	}
	return (count);
}

t_stack	*get_stack_from_input(char *input)
{
	int		i;
	t_stack	*new_stack;
	t_list	*new_elem;
	char	**str_elems;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (0);
	str_elems = ft_split(input, ' ');
	if (!str_elems)
		return (free(new_stack), NULL);
	i = 0;
	while (str_elems[i])
	{
		new_elem = stack_new(get_pos_in_stack(str_elems, i));
		if (!new_elem)
			return (free(str_elems), stack_free(new_stack), NULL);
		stack_addback(new_stack, new_elem);
		i++;
	}
	return (free(str_elems), new_stack);
}

t_stack	*get_stack_from_inputs(int elems, char **argv)
{
	int		i;
	t_stack	*new_stack;
	t_list	*new_elem;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (0);
	i = 0;
	while (i < elems - 1)
	{
		new_elem = stack_new(get_pos_in_stack(argv + 1, i));
		if (!new_elem)
			return (stack_free(new_stack), NULL);
		stack_addback(new_stack, new_elem);
		i++;
	}
	return (new_stack);
}
