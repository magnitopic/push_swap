/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:10:37 by alaparic          #+#    #+#             */
/*   Updated: 2023/05/08 08:06:14 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Counts the necessary steps to get each values in `stack_a` to the front of the
 * stack. Negative values mean it should be moved with `rra` to save moves.
*/
void	count_steps_a(t_stack *stack_a)
{
	int	len;
	int	str_len;

	str_len = stack_size(stack_a);
	len = 0;
	while (stack_a != NULL)
	{
		if (len <= (str_len / 2))
			stack_a->steps_a = len;
		else
			stack_a->steps_a = len - str_len;
		stack_a = stack_a->next;
		len++;
	}
}

/**
 * To count the steps for `stack_b` we need to know what value we want to reach.
 * So we determine the target where the value should be positioned.
*/
static int	get_target(t_stack *stack_a, t_stack *stack_b, int s_b_size)
{
	int		target;
	t_stack	*stack_b_cpy;
	int		lst_value;

	stack_b_cpy = stack_b;
	if (stack_a->value < min(stack_b) || stack_a->value > max(stack_b))
			target = max(stack_b);
	else
	{
		lst_value = get(stack_b, s_b_size - 1)->value;
		while (stack_b_cpy->next != NULL)
		{
			if (stack_a->value < stack_b_cpy->value
				&& stack_a->value > stack_b_cpy->next->value)
				target = stack_b_cpy->next->value;
			else if (stack_a->value
				< lst_value
				&& stack_a->value > stack_b->value)
				target = stack_b->value;
			stack_b_cpy = stack_b_cpy->next;
		}
	}
	return (target);
}

/**
 * Knowing the target we count how many steps we need to move `stack_b`.
 * That value is saved in `steps_b` of the value in `stack_a` that we are
 * looking at.
*/
void	count_steps_b(t_stack *stack_a, t_stack *stack_b)
{
	int	target;
	int	s_b_size;

	s_b_size = stack_size(stack_b);
	while (stack_a != NULL)
	{
		target = get_target(stack_a, stack_b, s_b_size);
		if (get_pos(stack_b, target) <= s_b_size / 2)
			stack_a->steps_b = get_pos(stack_b, target);
		else
			stack_a->steps_b = -(s_b_size \
			- get_pos(stack_b, target));
		stack_a = stack_a->next;
	}
}

/**
 * To get how many total steps need to be taken to move each value we
 * sum the values in `steps_a` and `steps_b` but with absolute values
 * since we have negative numbers to indicate they need to move backwards.
*/
void	totalize(t_stack *stack_a)
{
	while (stack_a != NULL)
	{
		if ((stack_a->steps_a * stack_a->steps_b) < 0)
			stack_a->total = abs(stack_a->steps_a) + abs(stack_a->steps_b);
		else
		{
			if (abs(stack_a->steps_a) > abs(stack_a->steps_b))
				stack_a->total = abs(stack_a->steps_a);
			else
				stack_a->total = abs(stack_a->steps_b);
		}
		stack_a = stack_a->next;
	}
}

/**
 * Having an absolute value we can decide what values will take the least
 * number of steps to move to `stack_b`.
*/
int	min_steps(t_stack **stack_a)
{
	int		pos;
	int		min_steps;
	int		abs_value;
	int		i;

	i = 0;
	min_steps = 214748367;
	while (i < stack_size(*stack_a))
	{
		abs_value = get(*stack_a, i)->total;
		if (abs_value < min_steps)
		{
			min_steps = abs_value;
			pos = i;
		}
		i++;
	}
	return (pos);
}
