/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:56:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/20 13:42:47 by alaparic         ###   ########.fr       */
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

char	*modern_times(t_stack *stack_a, t_stack *stack_b)
{
	char	*moves;
	/* int		lst_len;

	lst_len = stack_size(stack_a); */
	moves = pb(&stack_a, &stack_b);
	moves = ft_strjoin(moves, pb(&stack_a, &stack_b));
	moves = ft_strjoin(moves, pb(&stack_a, &stack_b));
	count_steps_a(stack_a);
	count_steps_b(stack_a, stack_b);
	/* while (lst_len > 0)							// TODO: improve with a better condition
	{

		moves = ft_strjoin(moves, move_number(stack_a, stack_b, min_steps));
		moves = ft_strjoin(moves, pb(&stack_a, &stack_b));
	} */
	return (moves);
}
