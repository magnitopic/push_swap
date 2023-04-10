/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:56:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/10 12:49:15 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	move_stack(t_stack **stack_a, t_stack **stack_b, int pos)
{
	int		i;

	i = 0;
	while (ft_abs(get(*stack_a, pos)->pasos_a) > i)
	{
		if (get(*stack_a, pos)->pasos_a > 0)
			write(1, ra(stack_a, stack_b), 3);
		else
			write(1, rra(stack_a, stack_b), 4);
		pos = min_steps(stack_a);
		i++;
	}
	i = 0;
	while (ft_abs(get(*stack_a, pos)->pasos_b) > i)
	{
		if (get(*stack_a, pos)->pasos_b > 0)
			write(1, rb(stack_a, stack_b), 3);
		else
			write(1, rrb(stack_a, stack_b), 4);
		i++;
	}
}

static void	synergy(t_stack **stack_a, t_stack **stack_b, int pos)
{
	t_stack	*value;

	value = get(*stack_a, pos);
	if (value->pasos_a * value->pasos_b > 0)
	{
		while (value->pasos_a != 0 && value->pasos_b != 0)
		{
			if (value->pasos_a > 0)
			{
				write(1, rr(stack_a, stack_b), 3);
				value->pasos_a--;
				value->pasos_b--;
			}
			else
			{
				write(1, rrr(stack_a, stack_b), 4);
				value->pasos_a++;
				value->pasos_b++;
			}
		}
		totaliza(*stack_a);
		pos = min_steps(stack_a);
	}
	move_stack(stack_a, stack_b, pos);
}

/**
 * We need to position the numbers in both our stacks so that the only thing
 * left is moving values from `stack_b` to `stack_a`.
 * We first position the biggest value in `stack_b` at the front of the list.
 * And we call the `sort_three` function, from the helpers file, to sort the
 * three numbers we left in `stack_a`.
 */
static void	order_stacks(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b)->value != max(*stack_b))
	{
		if (max(*stack_b) <= stack_size(*stack_b) / 2)
			write(1, rb(stack_a, stack_b), 3);
		else
			write(1, rrb(stack_a, stack_b), 4);
	}
	sort_three(stack_a, stack_b);
}

static void	zipper(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*s_a_cpy;
	int		i;

	i = 3;
	s_a_cpy = get(*stack_a, stack_size(*stack_a) - i--);
	while (stack_size(s_a_cpy))
	{
		if (max(s_a_cpy) < max(*stack_b))
			write(1, pa(stack_a, stack_b), 3);
		else
		{
			write(1, rra(stack_a, stack_b), 4);
			s_a_cpy = get(*stack_a, stack_size(*stack_a) - i--);
		}
	}
	while (stack_size(*stack_b))
		write(1, pa(stack_a, stack_b), 3);
}

void	modern_times(t_stack **stack_a, t_stack **stack_b)
{
	int		pos;

	write(1, pb(stack_a, stack_b), 3);
	write(1, pb(stack_a, stack_b), 3);
	while (stack_size(*stack_a) > 3)
	{
		count_steps_a(*stack_a);
		count_steps_b(*stack_a, *stack_b);
		totaliza(*stack_a);
		pos = min_steps(stack_a);
		synergy(stack_a, stack_b, pos);
		write(1, pb(stack_a, stack_b), 3);
	}
	order_stacks(stack_a, stack_b);
	zipper(stack_a, stack_b);
}
