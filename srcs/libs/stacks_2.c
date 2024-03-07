/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:41:48 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/06 15:11:08 by gachalif         ###   ########.fr       */
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
	while (current && current->next)
	{
		to_free = current;
		current = current->next;
		if (to_free)
			free(to_free);
	}
	free(stack);
}

int	stack_is_limit(t_stack *stack)
{
	t_list	*current;
	int		max;
	int		min;

	max = -2147483648;
	min = 2147483647;
	current = stack->head;
	while (current)
	{
		if (current->content < min)
			min = current->content;
		if (current->content > max)
			max = current->content;
		current = current->next;
	}
	if (stack->head && stack->head->content >= max)
		return (1);
	else if (stack->head && stack->head->content <= min)
		return (-1);
	else
		return (0);
}
