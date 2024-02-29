/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:54:00 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/29 10:22:02 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	stack_addback(t_stack **head, t_stack *to_add)
{
	t_stack	*current;

	if (*head == 0)
	{
		*head = to_add;
		return ;
	}
	current = *head;
	while (current && current->next)
		current = current->next;
	current->next = to_add;
}

void	stack_addfront(t_stack **head, t_stack *to_add)
{
	t_stack	*next;

	next = *head;
	to_add->next = next;
	*head = to_add;
}

void	stack_put(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!*from)
		return ;
	temp = (*from)->next;
	(*from)->next = 0;
	stack_addfront(to, *from);
	*from = temp;
}

void	stack_swap(t_stack **head, t_stack	*to_swap_a, t_stack	*to_swap_b)
{
	t_stack	*prev[2];
	t_stack	*current;

	prev[0] = 0;
	prev[1] = 0;
	current = *head;
	while (current->next)
	{
		if (current->next == to_swap_a)
			prev[0] = current;
		else if (current->next == to_swap_b)
			prev[1] = current;
		current = current->next;
	}
	if (prev[0])
		prev[0]->next = to_swap_b;
	if (prev[1])
		prev[1]->next = to_swap_a;
	current = to_swap_a->next;
	to_swap_a->next = to_swap_b->next;
	to_swap_b->next = current;
	if (*head == to_swap_a)
		*head = to_swap_b;
	else if (*head == to_swap_b)
		*head = to_swap_a;
}

void	stack_rot(t_stack **head)
{
	t_stack	*current;
	t_stack	*temp;

	if (!(*head) || !(*head)->next)
		return ;
	current = *head;
	while (current->next)
		current = current->next;
	temp = *head;
	*head = temp->next;
	temp->next = NULL;
	current->next = temp;
}

void	stack_print(t_stack *head)
{
	while (head)
	{
		printf("[%i] ", head->content);
		head = head->next;
	}
}
