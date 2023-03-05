/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:02 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/05 12:22:08 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Function to check wether the stacks are sorted.
 * For that to be true stack_b must be empty and
 * stack_a must have all values from smallest to largest
 */

int	ft_issorted(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	len;
	int	first_value;
	int	second_value;

	if (ft_lstsize(stack_b) != 0)
		return (0);
	i = 0;
	len = ft_lstsize(stack_a);
	while ((len - 1) > i)
	{
		first_value = *(int *)ft_get(stack_a, i)->content;
		second_value = *(int *)ft_get(stack_a, i + 1)->content;
		if (first_value > second_value)
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

int	ft_is_in_list(t_entry *dict, t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	while (i < dict_size(dict))
	{
		if (ft_lstcompare(dict_get(dict, i)->stack_a, stack_a)
			&& ft_lstcompare(dict_get(dict, i)->stack_b, stack_b))
			return (1);
		i++;
	}
	return (0);
}
