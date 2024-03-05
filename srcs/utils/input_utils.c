/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:40:50 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/04 15:28:31 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack)
{
	t_list	*temp;

	while (stack->head)
	{
		temp = stack->head->next;
		free(stack->head);
		stack->head = temp;
	}
	free(stack);
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
		new_elem = stack_new(ft_atoi(str_elems[i]));
		if (!new_elem)
			return (free_stack(new_stack), NULL);
		stack_addback(new_stack, new_elem);
		i++;
	}
	return (new_stack);
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
		new_elem = stack_new(ft_atoi((argv[i + 1])));
		if (!new_elem)
			return (free_stack(new_stack), NULL);
		stack_addback(new_stack, new_elem);
		i++;
	}
	return (new_stack);
}
