/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:56:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/07 17:58:32 by alaparic         ###   ########.fr       */
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
		moves = ft_strjoin(moves, move_number(stack_a, stack_b, min_steps));
		moves = ft_strjoin(moves, pb(&stack_a, &stack_b));
	}
	
	return (moves);
}
