/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:41:48 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/05 13:51:43 by gachalif         ###   ########.fr       */
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
	t_list	*last;

	last = stack->head;
	while (last->next)
		last = last->next;
	last->next = stack->head;
	stack->head = last;
	while (last->next)
	{
		if (last->next == stack->head)
			last->next = 0;
		last = last->next;
	}
}

void	stack_swap(t_stack *stack)
{
	
}
