/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:40:38 by gachalif          #+#    #+#             */
/*   Updated: 2024/03/04 16:06:58 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	pow(size_t n, size_t p)
{
	size_t	mult;

	if (p == 0)
		return (1);
	p -= 1;
	mult = n;
	while (p > 1)
	{
		n *= mult;
		p--;
	}
	return (n);
}

static int	get_digit(size_t from, size_t digit)
{
	return ((from / pow(10, digit)) % 10);
}

static int	is_sorted(t_stack	*stack, t_stack	*stack_2)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = stack->head;
	head_b = stack_2->head;
	while (stack_2 ->head && head_b->next)
	{
		if (head_b->content < head_b->next->content)
			return (0);
		head_b = head_b->next;
		if (head_b && head_a && !head_b->next)
		{
			if (head_b->content < head_a->content)
				return (0);
		}
	}
	head_b = head_a;
	while (head_b && head_b->next)
	{
		if (head_b->content > head_b->next->content)
			return (0);
		head_b = head_b->next;
	}
	return (1);
}

int	contains_digit(t_list *head, int depth, int digit)
{
	t_list	*temp;

	temp = head;
	while (temp)
	{
		if (get_digit(temp->content, depth) == digit)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	radix_pass(t_stack *s_a, t_stack	*s_b, size_t	depth)
{
	int		i;

	i = 0;
	while (i < 10 && !is_sorted(s_a, s_b))
	{
		while (contains_digit(s_a->head, depth, i) && !is_sorted(s_a, s_b))
		{
			while (s_a->head && get_digit(s_a->head->content, depth) == i)
			{
				if (depth % 2 == 0)
					printf("pb\n");
				else
					printf("pa\n");
				stack_put(s_a, s_b);
			}
			if (s_a->head && contains_digit(s_a->head, depth, i))
			{
				if (depth % 2 == 0)
					printf("ra\n");
				else
					printf("rb\n");
				stack_rot(s_a);
			}
		}
		i++;
	}
}

void	radix(t_stack *s_a, t_stack	*s_b)
{
	int		depth;

	depth = 0;
	while (!is_sorted(s_a, s_b) && depth < 10)
	{
		if (depth % 2 == 0)
			radix_pass(s_a, s_b, depth);
		else
			radix_pass(s_b, s_a, depth);
		depth++;
	}
}
