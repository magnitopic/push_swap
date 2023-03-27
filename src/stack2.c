/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:10:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/27 11:59:10 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * More functions for t_stack
 * -	Print the stack values
 * -	Find the max value
 * -	Find the min value
*/
void	stack_print(t_stack *lst)
{
	t_stack	*node;

	if (lst == NULL)
	{
		ft_printf("NULL\n");
		return ;
	}
	node = lst;
	while (node != NULL)
	{
		ft_printf("%i ", (node->value));
		node = node->next;
	}
	ft_printf("\n");
}

int	max(t_stack *stack)
{
	int	max;

	max = stack->value;
	while (stack != NULL)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	min(t_stack *stack)
{
	int	min;

	min = stack->value;
	while (stack != NULL)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

t_stack	*get_pos(t_stack *stack, int value)
{
	while (stack->value != value)
		stack = stack->next;
	return (stack);
}
