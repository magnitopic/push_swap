/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:56:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/15 17:03:17 by alaparic         ###   ########.fr       */
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
		//ft_printf("Value: %d pasos_a: %d\n", stack_a->value, stack_a->pasos_a);
		stack_a = stack_a->next;
		len++;
	}
}

/* stack_a->pasos_a = (str_len - len) * -1;
		ft_printf("%d\n", stack_a->pasos_a);
		stack_a = stack_a->next;
		len++; */

static void	count_steps_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	str_len;

	str_len = stack_size(stack_b);
	while (stack_a != NULL)
	{
		if (stack_a->value < get(stack_b, 1)->value
			&& stack_a->value > get(stack_b, str_len - 1)->value)
		{
			if (i < (str_len / 2))
				stack_a->pasos_b = 0;
			else
				stack_a->pasos_b = 0;
		}
		i = 1;
		while (get(stack_b, i) != NULL)
		{
			ft_printf("stack_a: %d stack_b: %d stack_b-1: %d \n", stack_a->value, get(stack_b, i)->value, get(stack_b, i - 1)->value);
			if (stack_a->value < get(stack_b, i)->value
				&& stack_a->value > get(stack_b, i -1)->value)
			{
				if (i < (str_len / 2))
					stack_a->pasos_b = i;
				else
					stack_a->pasos_b = i - str_len;
			}
			i++;
		}
		ft_printf("Value: %d pasos_b: %d\n", stack_a->value, stack_a->pasos_b);
		stack_print(stack_a);
		stack_print(stack_b);
		stack_a = stack_a->next;
	}
}

static void	count_min_steps(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	count_steps_a(stack_a);
	count_steps_b(stack_a, stack_b);
}

char	*modern_times(t_stack *stack_a, t_stack *stack_b)
{
	char	*moves;
	int		lst_len;

	lst_len = stack_size(stack_a);
	moves = pb(&stack_a, &stack_b);
	moves = ft_strjoin(moves, pb(&stack_a, &stack_b));
	count_min_steps(stack_a, stack_b);
	/* while (lst_len > 0)							// TODO: improve with a better condition
	{

		moves = ft_strjoin(moves, move_number(stack_a, stack_b, min_steps));
		moves = ft_strjoin(moves, pb(&stack_a, &stack_b));
	} */
	return (moves);
}
