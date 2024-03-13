/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:41:48 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/12 11:55:35 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_rot(t_stack *stack)
{
	t_list	*current;

	if (!stack->head || !stack->head->next)
		return ;
	current = stack->head;
	while (current->next)
		current = current->next;
	current->next = stack->head;
	current = stack->head->next;
	stack->head->next = NULL;
	stack->head = current;
}

void	stack_rrot(t_stack *stack)
{
	t_list	*new_head;
	t_list	*new_last;

	if (!stack->head || !stack->head->next)
		return ;
	new_head = stack->head;
	while (new_head->next)
	{
		new_last = new_head;
		new_head = new_head->next;
	}
	new_last->next = 0;
	new_head->next = stack->head;
	stack->head = new_head;
}

void	stack_swap(t_stack *stack)
{
	t_list	*to_first;
	t_list	*to_next;

	if (!stack->head || !stack->head->next)
		return ;
	to_next = stack->head;
	to_first = stack->head->next;
	to_next->next = to_first->next;
	to_first->next = to_next;
	stack->head = to_first;
}

void	stack_free(t_stack *stack)
{
	t_list	*current;
	t_list	*to_free;

	current = stack->head;
	while (current)
	{
		to_free = current;
		current = current->next;
		if (to_free)
			free(to_free);
	}
	free(stack);
}

t_list	*stack_min(t_stack *stack)
{
	t_list	*min_list;
	t_list	*current;
	int		min;

	current = stack->head;
	min_list = current;
	min = 2147483647;
	while (current)
	{
		if (current->content < min)
		{
			min = current->content;
			min_list = current;
		}
		current = current->next;
	}
	return (min_list);
}
