/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:56:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/05 18:26:21 by alaparic         ###   ########.fr       */
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

	return (aggregate(steps_a, steps_b));
}

int	count_steps_a(stack_a)
{
	int	i;

	i = 0;
	
}