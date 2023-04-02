/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:10:37 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/02 14:32:13 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	count_steps_a(t_stack *stack_a)
{
	int	len;
	int	str_len;

	str_len = stack_size(stack_a);
	len = 0;
	while (stack_a != NULL)
	{
		if (len <= (str_len / 2))
			stack_a->pasos_a = len;
		else
			stack_a->pasos_a = len - str_len;
		stack_a = stack_a->next;
		len++;
	}
}

static int	get_target(t_stack *stack_a, t_stack *stack_b)
{
	int		target;
	t_stack	*stack_b_cpy;

	stack_b_cpy = stack_b;
	if (stack_a->value < min(stack_b) || stack_a->value > max(stack_b))
			target = max(stack_b);
	else
	{
		while (stack_b_cpy->next != NULL)
		{
			if (stack_a->value < stack_b_cpy->value
				&& stack_a->value > stack_b_cpy->next->value)
				target = stack_b_cpy->next->value;
			else if (stack_a->value
				< get(stack_b, stack_size(stack_b) - 1)->value
				&& stack_a->value > stack_b->value)
				target = stack_b->value;
			stack_b_cpy = stack_b_cpy->next;
		}
	}
	return (target);
}

void	count_steps_b(t_stack *stack_a, t_stack *stack_b)
{
	int		target;

	while (stack_a != NULL)
	{
		target = get_target(stack_a, stack_b);
		if (get_pos(stack_b, target) <= stack_size(stack_b) / 2)
			stack_a->pasos_b = get_pos(stack_b, target);
		else
			stack_a->pasos_b = -(stack_size(stack_b) \
			- get_pos(stack_b, target));
		stack_a = stack_a->next;
	}
}

void	totaliza(t_stack *stack_a)
{
	while (stack_a != NULL)
	{
		if ((stack_a->pasos_a * stack_a->pasos_b) < 0)
			stack_a->total = abs(stack_a->pasos_a) + abs(stack_a->pasos_b);
		else
		{
			if (abs(stack_a->pasos_a) > abs(stack_a->pasos_b))
				stack_a->total = abs(stack_a->pasos_a);
			else
				stack_a->total = abs(stack_a->pasos_b);
		}
		stack_a = stack_a->next;
	}
}

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
