/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:40:38 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/28 15:36:45 by gachalif         ###   ########.fr       */
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
	while (stack_2 && stack_2->next)
	{
		if (stack_2->content < stack_2->next->content)
			return (0);
		stack_2 = stack_2->next;
		if (!stack_2->next)
		{
			stack_2->next = stack;
			if (stack_2->content < stack_2->next->content)
				return (0);
			break ;
		}
	}
	stack_2 = stack;
	while (stack_2 && stack_2->next)
	{
		if (stack_2->content > stack_2->next->content)
			return (0);
		stack_2 = stack_2->next;
	}
	return (1);
}

// void	radix_pass(t_stack **stack, size_t	digit)
// {
// 	t_stack	*cur;

// 	while (!is_sorted(*stack, digit))
// 	{
// 		cur = *stack;
// 		while (cur->next)
// 		{
// 			if (get_digit(cur->content, digit) > \
// 			get_digit(cur->next->content, digit))
// 			{
// 				printf("sa ");
// 				stack_swap(stack, cur, cur->next);
// 				break ;
// 			}
// 			cur = cur->next;
// 			printf("ra ");
// 		}
// 	}
// 	if (!is_sorted(*stack, 0) && digit < 10)
// 		radix_pass(stack, digit + 1);
// 	return ;
// }

int	contains_digit(t_stack *stack, int depth, int digit)
{
	while (stack)
	{
		if (get_digit(stack->content, depth) == digit)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	radix_pass_even(t_stack **s_a, t_stack	**s_b, size_t	depth)
{
	int		i;

	i = 0;
	while (i < 10 && !is_sorted(*s_a, *s_b))
	{
		while (contains_digit(*s_a, depth, i) && !is_sorted(*s_a, *s_b))
		{
			if (get_digit((*s_a)->content, depth) == i)
			{
				printf("pa ");
				stack_put(s_a, s_b);
			}
			else
			{
				printf("ra ");
				stack_rot(s_a);
			}
		}
		i++;
	}
}
