/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:56:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/01 21:28:07 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	*move_stacks(t_stack **stack_a, t_stack **stack_b, int pos)
{
	int		i;
	char	*moves;

	i = 0;
	moves="";
	while (ft_abs(get(*stack_a, pos)->pasos_a) > i)
	{
		if (get(*stack_a, pos)->pasos_a > 0)
		{
			moves = ft_strjoin(moves, ra(stack_a, stack_b));
		}
		else
			moves = ft_strjoin(moves, rra(stack_a, stack_b));
		pos = min_steps(stack_a);
		i++;
	}
	i = 0;
	while (ft_abs(get(*stack_a, pos)->pasos_b) > i)
	{
		if (get(*stack_a, pos)->pasos_b > 0)
			moves = ft_strjoin(moves, rb(stack_a, stack_b));
		else
			moves = ft_strjoin(moves, rrb(stack_a, stack_b));
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
		while (value->pasos_a != 0 || value->pasos_b != 0)
		{
			if (value->pasos_a > 0)
			{
				moves = ft_strjoin(moves, rr(stack_a, stack_b));
				value->pasos_a--;
				value->pasos_b--;
			}
			else
			{
				moves = ft_strjoin(moves, rrr(stack_a, stack_b));
				value->pasos_a++;
				value->pasos_b++;
			}
		}
		pos = min_steps(stack_a);
	}
	moves = ft_strjoin(moves, move_stacks(stack_a, stack_b, pos));
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
			moves = ft_strjoin(moves, rb(stack_a, stack_b));
		else
			moves = ft_strjoin(moves, rrb(stack_a, stack_b));
	}
	moves = sort_three(stack_a, stack_b, moves);
	return (moves);
}

/* static char	*zipper(t_stack **stack_a, t_stack **stack_b, char *moves)
{
	while (ft_issorted(*stack_a, *stack_b) == 0)
	{
		stack_print(*stack_a);
		stack_print(*stack_b);
		if (get(*stack_a, stack_size(*stack_a) - 1)->value < (*stack_b)->value)
			moves = ft_strjoin(moves, pa(stack_a, stack_b));
		else
			moves = ft_strjoin(moves, rra(stack_a, stack_b));
	}
	return (moves);
} */

char	*modern_times(t_stack **stack_a, t_stack **stack_b)
{
	char	*moves;
	int		pos;

	moves = pb(stack_a, stack_b);
	moves = ft_strjoin(moves, pb(stack_a, stack_b));
	while (stack_size(*stack_a) > 3)
	{
		/* ft_printf("\nStackA\t");
		for (int i = 0; i < stack_size(*stack_a); i++)
			ft_printf("%d\t",get(*stack_a, i)->value);
		ft_printf("\nStackB\t");
		for (int i = 0; i < stack_size(*stack_b); i++)
			ft_printf("%d\t",get(*stack_b, i)->value);
		count_steps_a(*stack_a);
		count_steps_b(*stack_a, *stack_b);
		totaliza(*stack_a);
		ft_printf("\nPasosA\t");
		for (int i = 0; i < stack_size(*stack_a); i++)
			ft_printf("%d\t",get(*stack_a, i)->pasos_a);
		ft_printf("\nPasosB\t");
		for (int i = 0; i < stack_size(*stack_a); i++)
			ft_printf("%d\t",get(*stack_a, i)->pasos_b);
		ft_printf("\nTotal:\t");
		for (int i = 0; i < stack_size(*stack_a); i++)
			ft_printf("%d\t",get(*stack_a, i)->total);
		ft_printf("\n*******************\n"); */
		pos = min_steps(stack_a);
		moves = synergy(stack_a, stack_b, pos, moves);
		moves = ft_strjoin(moves, pb(stack_a, stack_b));
	}
	moves = order_stacks(stack_a, stack_b, moves);
	/* moves = zipper(stack_a, stack_b, moves);
	stack_print(*stack_a);
	stack_print(*stack_b); */
	return (moves);
}
