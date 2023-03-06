/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:56:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/06 19:06:23 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*modern_times(t_list *stack_a, t_list *stack_b)
{
	char	*moves;
	int		*min_steps;

	moves = pb(&stack_a, &stack_b);
	moves = ft_strjoin(moves, pb(&stack_a, &stack_b));
	while (ft_lstsize(stack_a) > 0)							// TODO: improve with a better condition
	{
		min_steps = count_min_steps(stack_a, stack_b);
	}
	return (moves);
}

int	*count_min_steps(t_list *stack_a, t_list *stack_b)
{
	int	*steps_a;
	int	*steps_b;

	steps_a = count_steps_a(stack_a);
	steps_b = count_steps_b(stack_b);
	return (ft_aggregate(steps_a, steps_b));
}

int	*count_steps_a(t_list *stack_a)
{
	int	i;
	int	lst_len;
	int	*n_steps;

	i = 0;
	lst_len = ft_lstsize(stack_a);
	n_steps = ft_calloc(lst_len, sizeof(int));
	while (i < lst_len)
	{
		if (i < (lst_len / 2)) // ? is 'i' the same as .index(i), same below ↓
			n_steps[i] = i;
		else
			n_steps[i] = -(lst_len - i);
	}
	return (n_steps);
}

int	count_steps_b(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	j;
	int	*n_steps;

	while (i < ft_lstsize(stack_a))
	{
		while (j < )
		{
			
		}
	}
}
