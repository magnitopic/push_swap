/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:56:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/05/09 07:55:00 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * Moves the stacks as `steps_a` and `steps_b` values of the specified element
 * in `stack_a`.
*/
static void	move_stack(t_stack **stack_a, t_stack **stack_b, int pos)
{
	int		i;

	i = 0;
	while (ft_abs(get(*stack_a, pos)->steps_a) > i)
	{
		if (get(*stack_a, pos)->steps_a > 0)
			write(1, ra(stack_a, stack_b), 3);
		else
			write(1, rra(stack_a, stack_b), 4);
		pos = min_steps(stack_a);
		i++;
	}
	i = 0;
	while (ft_abs(get(*stack_a, pos)->steps_b) > i)
	{
		if (get(*stack_a, pos)->steps_b > 0)
			write(1, rb(stack_a, stack_b), 3);
		else
			write(1, rrb(stack_a, stack_b), 4);
		i++;
	}
}

/**
 * Now that we know what number takes the least amount of moves we can save some
 * steps by determining if we can have some synergy with our moves.
 * If steps for stack_a and stack_b have the same symbol it means that there is
 * synergy. Witch means we can use `rr` or `rrr` to move both stacks at the same
 * time to save moves.
*/
static void	synergy(t_stack **stack_a, t_stack **stack_b, int pos)
{
	t_stack	*value;

	value = get(*stack_a, pos);
	if (value->steps_a * value->steps_b > 0)
	{
		while (value->steps_a != 0 && value->steps_b != 0)
		{
			if (value->steps_a > 0)
			{
				write(1, rr(stack_a, stack_b), 3);
				value->steps_a--;
				value->steps_b--;
			}
			else
			{
				write(1, rrr(stack_a, stack_b), 4);
				value->steps_a++;
				value->steps_b++;
			}
		}
		totalize(*stack_a);
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

/**
 * All that's left is to move and order all values in `stack_a`.
 * Since we have 3 values in `stack_a` we must move them when
 * the next number to move from `stack_b` is smaller.
*/
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

/**
 * The modern times algorithm sends the first two numbers to `stack_b` from
 * the start just to have something to compare with the rest of the numbers.
 * Next we will count for each value the mount of moves we need to position it
 * in `stack_b`, both the steps that need to be moved in `stack_a` and `stack_b`
 * represented by `steps_a` and `steps_b` in each element in `stack_a`.
 * Once we know the value with the least number of moves we check if there is
 * synergy. After we have moved all except three values to `stack_b` we order
 * those 3 values and call the `zipper` function which will align all the values.
*/
void	modern_times(t_stack **stack_a, t_stack **stack_b)
{
	int		pos;

	write(1, pb(stack_a, stack_b), 3);
	write(1, pb(stack_a, stack_b), 3);
	while (stack_size(*stack_a) > 3)
	{
		count_steps_a(*stack_a);
		count_steps_b(*stack_a, *stack_b);
		totalize(*stack_a);
		pos = min_steps(stack_a);
		synergy(stack_a, stack_b, pos);
		write(1, pb(stack_a, stack_b), 3);
	}
	order_stacks(stack_a, stack_b);
	zipper(stack_a, stack_b);
}
