/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:56:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/21 18:20:17 by alaparic         ###   ########.fr       */
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
		if (len < (str_len / 2))
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
	int		len;

	while (stack_a != NULL)
	{
		stack_b_cpy = stack_b;
		len = 1;
		if (stack_a->value > stack_b->value
			&& stack_a->value < get(stack_b, stack_size(stack_b) - 1)->value)
				stack_a->pasos_b = 0;
		while (stack_b_cpy->next != NULL)
		{
			if (stack_a->value > stack_b_cpy->value
				&& stack_a->value < get(stack_b, len)->value)
			{
				if (len < (stack_size(stack_b) / 2))
					stack_a->pasos_b = len;
				else
					stack_a->pasos_b = len - stack_size(stack_b);
			}
			stack_b_cpy = stack_b_cpy->next;
			len++;
		}
		stack_a = stack_a->next;
	}
}

static char	*move_number(t_stack **stack_a, t_stack **stack_b)
{
	char	*moves;
	int		position;
	int		min_steps;
	int		abs_value;
	int		i;

	moves = "";
	min_steps = 214748367;
	i = 0;
	while (i < stack_size(*stack_a))
	{
		abs_value = ft_abs(get(*stack_a, i)->pasos_a) \
		+ ft_abs(get(*stack_a, i)->pasos_b);
		if (abs_value < min_steps)
		{
			min_steps = abs_value;
			position = i;
		}
		i++;
	}
	i = 0;
	while (i < ft_abs(get(*stack_a, position)->pasos_a))
	{
		if (get(*stack_a, position)->pasos_a > 0)
			moves = ft_strjoin(moves, ra(stack_a, stack_b));
		else if (get(*stack_a, position)->pasos_a < 0)
			moves = ft_strjoin(moves, rra(stack_a, stack_b));
		i++;
	}
	i = 0;
	while (i < ft_abs(get(*stack_a, position)->pasos_b))
	{
		if (get(*stack_a, position)->pasos_b > 0)
			moves = ft_strjoin(moves, rb(stack_a, stack_b));
		else if (get(*stack_a, position)->pasos_b < 0)
			moves = ft_strjoin(moves, rrb(stack_a, stack_b));
		i++;
	}
	return (moves);
}

char	*modern_times(t_stack *stack_a, t_stack *stack_b)
{
	char	*moves;
	int		lst_len;

	lst_len = stack_size(stack_a);
	moves = pb(&stack_a, &stack_b);
	moves = ft_strjoin(moves, pb(&stack_a, &stack_b));
	while (stack_size(stack_a) > 0)
	{
		count_steps_a(stack_a);
		count_steps_b(stack_a, stack_b);
		/* imprimir pasos stack_a */
		stack_print(stack_a);
		stack_print(stack_b);
		for (int i = 0; i < stack_size(stack_a); i++)
		{
			ft_printf("%d-> %d  %d\n",get(stack_a, i)->value, get(stack_a, i)->pasos_a, get(stack_a, i)->pasos_b);
		}
		moves = ft_strjoin(moves, move_number(&stack_a, &stack_b));
		moves = ft_strjoin(moves, pb(&stack_a, &stack_b));
		stack_print(stack_a);
		stack_print(stack_b);
		ft_printf("========\n");
	}
	return (moves);
}
