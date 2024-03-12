/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:36:31 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/12 10:53:33 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_list	*current;

	current = stack->head;
	if (!current)
		return (1);
	while (current && current->next)
	{
		if (current->content < current->next->content)
			current = current->next;
		else
			return (0);
	}
	return (1);
}

int	is_sorted_rev(t_stack *stack)
{
	t_list	*current;

	current = stack->head;
	if (!current)
		return (1);
	while (current && current->next)
	{
		if (current->content > current->next->content)
			current = current->next;
		else
			return (0);
	}
	return (1);
}

int	get_digit_at_pos(int base10, int pos)
{
	while (pos > 0)
	{
		base10 /= 2;
		pos--;
	}
	return (base10 % 2);
}

int	stack_contains_bit_unset(t_stack *stack, int pos)
{
	t_list	*current;

	current = stack->head;
	while (current && current->next)
	{
		if (get_digit_at_pos(current->content, pos) == 0)
			return (1);
		current = current->next;
	}
	return (0);
}

int	get_closest_pos(t_stack *stack, t_list *target)
{
	t_list	*current;
	int		r_moves;
	int		rr_moves;
	int		r_moves_locked;

	current = stack->head;
	if (current == target)
		return (0);
	r_moves = 0;
	rr_moves = stack_size(stack);
	r_moves_locked = 0;
	while (current->next)
	{
		if (current == target)
			r_moves_locked = 1 ;
		if (!r_moves_locked)
			r_moves++;
		rr_moves--;
		current = current->next;
	}
	if (r_moves <= rr_moves)
		return (r_moves);
	else
		return (-rr_moves);
}
