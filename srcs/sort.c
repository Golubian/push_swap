/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:28:09 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/12 11:54:15 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_pass(t_stack	*from, t_stack *to, int pos)
{
	t_list	*start;

	start = from->head;
	while (stack_contains_bit_unset(from, pos) \
	&& !(is_sorted(from) && is_sorted_rev(to)))
	{
		if (get_digit_at_pos(from->head->content, pos) == 0)
		{
			if (from->head == start)
				start = start->next;
			pb(from, to);
		}
		else
			ra(from);
	}
	while (from->head != start && !(is_sorted(from) && is_sorted_rev(to)))
	{
		if (get_closest_pos(from, start) > 0)
			ra(from);
		else
			rra(from);
	}
	while (to->head)
		pa(from, to);
}

void	radix_sort(t_stack	*stack_a, t_stack *stack_b)
{
	int		pos;

	pos = 0;
	while (!(stack_a->head && is_sorted(stack_a)))
	{
		radix_pass(stack_a, stack_b, pos);
		pos++;
	}
	while (stack_b->head)
		pa(stack_a, stack_b);
}

void	sort_3(t_stack *stack_a)
{
	t_list	*current;

	while (!is_sorted(stack_a))
	{
		current = stack_a->head;
		if (current->content > current->next->content)
			sa(stack_a);
		else
			rra(stack_a);
	}
}

void	tiny_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	while (stack_size(stack_a) > 3)
	{
		if (get_closest_pos(stack_a, stack_min(stack_a)) > 0)
			ra(stack_a);
		else if (get_closest_pos(stack_a, stack_min(stack_a)) < 0)
			rra(stack_a);
		else
			pb(stack_a, stack_b);
	}
	sort_3(stack_a);
	while (stack_b->head)
		pa(stack_a, stack_b);
}
