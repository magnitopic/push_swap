/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:56:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/05 16:09:11 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*move_stack(t_stack **stack_a, t_stack **stack_b, int pos, char *moves)
{
	int		i;

	i = 0;
	while (ft_abs(get(*stack_a, pos)->pasos_a) > i)
	{
		if (get(*stack_a, pos)->pasos_a > 0)
			moves = ft_fstrjoin(moves, ra(stack_a, stack_b));
		else
			moves = ft_fstrjoin(moves, rra(stack_a, stack_b));
		pos = min_steps(stack_a);
		i++;
	}
	i = 0;
	while (ft_abs(get(*stack_a, pos)->pasos_b) > i)
	{
		if (get(*stack_a, pos)->pasos_b > 0)
			moves = ft_fstrjoin(moves, rb(stack_a, stack_b));
		else
			moves = ft_fstrjoin(moves, rrb(stack_a, stack_b));
		i++;
	}
	return (moves);
}

static char	*synergy(t_stack **stack_a, t_stack **stack_b, int pos, char *moves)
{
	t_stack	*value;

	value = get(*stack_a, pos);
	if (value->pasos_a * value->pasos_b > 0)
	{
		while (value->pasos_a != 0 && value->pasos_b != 0)
		{
			if (value->pasos_a > 0)
			{
				moves = ft_fstrjoin(moves, rr(stack_a, stack_b));
				value->pasos_a--;
				value->pasos_b--;
			}
			else
			{
				moves = ft_fstrjoin(moves, rrr(stack_a, stack_b));
				value->pasos_a++;
				value->pasos_b++;
			}
		}
		pos = min_steps(stack_a);
	}
	moves = move_stack(stack_a, stack_b, pos, moves);
	return (moves);
}

/**
 * We need to position the numbers in both our stacks so that the only thing
 * left is moving values from `stack_b` to `stack_a`.
 * We first position the biggest value in `stack_b` at the front of the list.
 * And we call the `sort_three` function, from the helpers file, to sort the
 * three numbers we left in `stack_a`.
 */
static char	*order_stacks(t_stack **stack_a, t_stack **stack_b, char *moves)
{
	while ((*stack_b)->value != max(*stack_b))
	{
		if (max(*stack_b) <= stack_size(*stack_b) / 2)
			moves = ft_fstrjoin(moves, rb(stack_a, stack_b));
		else
			moves = ft_fstrjoin(moves, rrb(stack_a, stack_b));
	}
	moves = sort_three(stack_a, stack_b, moves);
	return (moves);
}

static char	*zipper(t_stack **stack_a, t_stack **stack_b, char *moves)
{
	t_stack	*s_a_cpy;
	int		i;

	i = 3;
	s_a_cpy = get(*stack_a, stack_size(*stack_a) - i--);
	while (stack_size(s_a_cpy))
	{
		if (max(s_a_cpy) < max(*stack_b))
			moves = ft_fstrjoin(moves, pa(stack_a, stack_b));
		else
		{
			moves = ft_fstrjoin(moves, rra(stack_a, stack_b));
			s_a_cpy = get(*stack_a, stack_size(*stack_a) - i--);
		}
	}
	while (stack_size(*stack_b))
		moves = ft_fstrjoin(moves, pa(stack_a, stack_b));
	return (moves);
}

char	*modern_times(t_stack **stack_a, t_stack **stack_b)
{
	char	*moves;
	int		pos;

	moves = pb(stack_a, stack_b);
	moves = ft_strjoin(moves, pb(stack_a, stack_b));
	while (stack_size(*stack_a) > 3)
	{
		count_steps_a(*stack_a);
		count_steps_b(*stack_a, *stack_b);
		totaliza(*stack_a);
		pos = min_steps(stack_a);
		moves = synergy(stack_a, stack_b, pos, moves);
		moves = ft_fstrjoin(moves, pb(stack_a, stack_b));
	}
	moves = order_stacks(stack_a, stack_b, moves);
	moves = zipper(stack_a, stack_b, moves);
	return (moves);
}
