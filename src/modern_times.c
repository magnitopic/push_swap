/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:56:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/29 12:59:25 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	count_steps_a(t_stack *stack_a)
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

static void	count_steps_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*stack_b_cpy;
	int	target;

	while (stack_a != NULL)
	{
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
				else if (stack_a->value < get(stack_b, stack_size(stack_b) - 1)->value
						&& stack_a->value > stack_b->value)
					target = stack_b->value;
				stack_b_cpy = stack_b_cpy->next;
			}
		}
		if (get_pos(stack_b, target) <= stack_size(stack_b) / 2)
			stack_a->pasos_b = get_pos(stack_b, target);
		else
			stack_a->pasos_b = -(stack_size(stack_b) - get_pos(stack_b, target));
		ft_printf("%d, ", target);
		stack_a = stack_a->next;
	}
	ft_printf("\n");
}

static void	totaliza(t_stack *stack_a)
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

static char	*move_stacks(t_stack **stack_a, t_stack **stack_b, int position)
{
	int	i;
	char	*moves;

	i = 0;
	moves = "";
	while (ft_abs(get(*stack_a, position)->pasos_a) > i)
	{
		if (get(*stack_a, position)->pasos_a > 0)
			moves = ft_strjoin(moves, ra(stack_a, stack_b));
		else
			moves = ft_strjoin(moves, rra(stack_a, stack_b));
		i++;
	}
	i = 0;
	while (ft_abs(get(*stack_a, position)->pasos_b) > i)
	{
		if (get(*stack_a, position)->pasos_b > 0)
			moves = ft_strjoin(moves, rb(stack_a, stack_b));
		else
			moves = ft_strjoin(moves, rrb(stack_a, stack_b));
		i++;
	}
	return (moves);
}

/* static void	gira_pillas(t_stack *stack_a, t_stack *stack_b, int pos)
{
	t_stack	*value;
	int		shared_values;
	int		i;

	value = get(stack_a, pos);
	i = 0;
	if (value->pasos_a * value->pasos_b > 0)
	{
		if (value->pasos_a < value->pasos_b)
			shared_values = value->pasos_a;
		else
			shared_values = value->pasos_b;
		while (i < shared_values)
		{
			if (value->pasos_a > 0)
				rr(&stack_a, &stack_b);
			else
				rrr(&stack_a, &stack_a);
			value->pasos_a--;
			value->pasos_b--;
		}
	}
	move_stacks(stack_a, stack_b)
} */

static int	min_steps(t_stack **stack_a)
{
	int		position;
	int		min_steps;
	int		abs_value;
	int		i;

	i = 0;
	min_steps = 214748367;
	while (i < stack_size(*stack_a))
	{
		abs_value = (*stack_a)->total;
		if (abs_value < min_steps)
		{
			min_steps = abs_value;
			position = i;
		}
		i++;
	}
	return (position);
}

char	*modern_times(t_stack *stack_a, t_stack *stack_b)
{
	char	*moves;

	moves = pb(&stack_a, &stack_b);
	moves = ft_strjoin(moves, pb(&stack_a, &stack_b));
	while (stack_size(stack_a) >= 3)
	{
		ft_printf("***********\n");
		stack_print(stack_a);
		stack_print(stack_b);
		count_steps_a(stack_a);
		count_steps_b(stack_a, stack_b);
		totaliza(stack_a);
		int steps_min = min_steps(&stack_a);
		moves = ft_strjoin(moves, move_stacks(&stack_a, &stack_b, steps_min));
		
		
		moves = ft_strjoin(moves, pb(&stack_a, &stack_b));
	}
	return (moves);
}
