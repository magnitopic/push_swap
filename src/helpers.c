/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:24:27 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/30 18:12:16 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Function to check wether the stacks are sorted.
 * For that to be true stack_b must be empty and
 * stack_a must have all values from smallest to largest
 */
int	ft_issorted(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	len;

	if (stack_size(stack_b) != 0)
		return (0);
	i = 0;
	len = stack_size(stack_a);
	while ((len - 1) > i)
	{
		if (get(stack_a, i)->value
			> get(stack_a, i + 1)->value)
			return (0);
		i++;
	}
	return (1);
}

/**
 * Recibes the dictionary and the two stacks.
 * Checks thru all entries in the dictionary comparing
 * them to stack_a and stack_b.
 * If the stack values are already in the dictionary 1 is returned, otherwise 0.
 */
int	ft_is_in_list(t_entry *dict, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < dict_size(dict))
	{
		if (compare(dict_get(dict, i)->stack_a, stack_a)
			&& compare(dict_get(dict, i)->stack_b, stack_b))
			return (1);
		i++;
	}
	return (0);
}

char	*sort_three(t_stack **a, t_stack **b, char *moves)
{
	if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value
		&& (*a)->value < (*a)->next->next->value)
		moves = ft_strjoin(ft_strjoin(ft_strjoin(moves, \
		ra(a, b)), sa(a, b)), rra(a, b));
	else if ((*a)->value > (*a)->next->value
		&& (*a)->next->value < (*a)->next->next->value
		&& (*a)->value < (*a)->next->next->value)
		moves = ft_strjoin(moves, sa(a, b));
	else if ((*a)->value < (*a)->next->value
		&& (*a)->next->value > (*a)->next->next->value
		&& (*a)->value > (*a)->next->next->value)
		moves = ft_strjoin(moves, rra(a, b));
	else if ((*a)->value > (*a)->next->value
		&& (*a)->next->value < (*a)->next->next->value
		&& (*a)->value > (*a)->next->next->value)
		moves = ft_strjoin(moves, ra(a, b));
	else if ((*a)->value > (*a)->next->value
		&& (*a)->next->value < (*a)->next->next->value
		&& (*a)->value > (*a)->next->next->value)
	{
		moves = ft_strjoin(moves, sa(a, b));
		moves = ft_strjoin(moves, rra(a, b));
	}
	return (moves);
}
