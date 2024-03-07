/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:28:09 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/07 10:13:30 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Problem is median changes, maybe save somewhere
void	put_fork(t_stack *stack_a, t_stack *stack_b, float range, int median)
{
	int	min_int;
	int	max_int;

	min_int = get_at_pos(stack_a, get_pos_from_perc(stack_a, .5 - range));
	max_int = get_at_pos(stack_a, get_pos_from_perc(stack_a, .5 + range));
	while (stack_contains_fork(stack_a, min_int, max_int))
	{
		if (get_closest_fork_pos(stack_a, min_int, max_int) == 0)
		{
			if (stack_a->head->content >= median)
			{
				pb(stack_a, stack_b);
				rb(stack_b);
			}
			else
				pb(stack_a, stack_b);
		}
		else if (get_closest_fork_pos(stack_a, min_int, max_int) > 0)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

int	get_closest_limit_pos(t_stack *stack, int min, int max)
{
	t_list	*current;
	int		r_moves;
	int		rr_moves;
	int		r_moves_locked;

	current = stack->head;
	if (!current || current->content <= min || current->content >= max)
		return (0);
	r_moves = 0;
	rr_moves = stack_size(stack);
	r_moves_locked = 0;
	while (current->next)
	{
		if (current->content <= min || current->content >= max)
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

// static int	stack_min(t_stack *stack)
// {
// 	t_list	*current;
// 	int		min;

// 	min = 2147483647;
// 	current = stack->head;
// 	while (current)
// 	{
// 		if (current->content < min)
// 			min = current->content;
// 		current = current->next;
// 	}
// 	return (min);
// }

// static int	stack_max(t_stack *stack)
// {
// 	t_list	*current;
// 	int		max;

// 	max = -2147483648;
// 	current = stack->head;
// 	while (current)
// 	{
// 		if (current->content > max)
// 			max = current->content;
// 		current = current->next;
// 	}
// 	return (max);
// }

int	is_sorted(t_stack *stack, int ascending)
{
	t_list	*current;

	current = stack->head;
	while (current && current->next)
	{
		if (current->content > current->next->content && !ascending)
			current = current->next;
		else if (current->content < current->next->content)
			current = current->next;
		else
			return (0);
	}
	return (1);
}

void	finalize_sort(t_stack *stack_a, t_stack *stack_b)
{
	while (!is_sorted(stack_b, 0) || stack_b->head)
	{
		if (stack_is_limit(stack_b) < 0)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if (stack_is_limit(stack_b) > 0)
			pa(stack_a, stack_b);
		else if (stack_b->head->content > stack_b->head->next->content)
		{
			sb(stack_b);
			rrb(stack_b);
		}
		else
			rb(stack_b);
	}
	while (!is_sorted(stack_a, 1))
	{
		if (stack_a->head->content < get_median(stack_a))
			rra(stack_a);
		else
			ra(stack_a);
	}
}
