/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:36:31 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/05 16:25:22 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Returns content at position X of sorted linked list.
	Ex:

	[8 2 -1 6]

	get_at_pos(-1) -> NULL
	get_at_pos(0) -> -1
	get_at_pos(1) -> 2
	get_at_pos(2) -> 6
	get_at_pos(3) -> 8
	get_at_pos(4) -> NULL
*/
int	get_at_pos(t_stack *stack, int pos)
{
	t_list	*current;
	t_list	*list;
	int		below;

	current = stack->head;
	while (current->next)
	{
		below = 0;
		list = stack->head;
		while (list->next)
		{
			if (list->content < current->content)
				below++;
			list = list->next;
		}
		if (below == pos)
			return (current->content);
		current = current->next;
	}
	return (-1);
}

/*
	Returns the median content of a stack.
	If the stack has an even number of elements,
	we just pick the latter of the two middle ones.
*/
int	get_median(t_stack *stack)
{
	int	to_find;

	to_find = stack_size(stack) / 2;
	return (get_at_pos(stack, to_find));
}

/*
	Returns the floored position at percentage in the array.
	Ex:
		stack = [-12 3 27 4]
		get_pos_from_perc(stack, 0.75) -> 3
		get_pos_from_perc(stack, 0.5)  -> 2
		get_pos_from_perc(stack, 0.25) -> 1
		get_pos_from_perc(stack, 0.15) -> 0
	
	Limits:
		0 >= perc < 1
*/
int	get_pos_from_perc(t_stack *stack, float perc)
{
	return ((int)(perc * (float)stack_size(stack)));
}
