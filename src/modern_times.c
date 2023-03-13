/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modern_times.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:56:12 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/13 17:12:53 by alaparic         ###   ########.fr       */
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
		//ft_printf("Value: %d pasos_a: %d\n", stack_a->value ,stack_a->pasos_a);
		stack_a = stack_a->next;
		len++;
	}
}

/* stack_a->pasos_a = (str_len - len) * -1;
		ft_printf("%d\n", stack_a->pasos_a);
		stack_a = stack_a->next;
		len++; */

/* static int	count_steps_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	*n_steps;
	int	maxinf;

	n_steps = ft_calloc(ft_lstsize(stack_a), sizeof(int));
	while (i < ft_lstsize(stack_a))
	{
		maxinf = ft_lstmin(stack_b);
		while (j < ft_lstsize(stack_b))
		{
			if ((int *)ft_get(stack_a, i)->content
				< (int *)ft_get(stack_b, j)->content)
			{
				if ((int *)ft_get(stack_b, j)->content
					< (int *)ft_get(stack_a, i)->content
					&& (int *)ft_get(stack_b, j)->content > maxinf)
					maxinf = (int *)ft_get(stack_b, j)->content;
			}
		}
		if (i < (lst_len / 2))
			n_steps[i] = i;
		else
			n_steps[i] = -(lst_len - i);
	}
} */

static void	count_min_steps(t_stack *stack_a, t_stack *stack_b)
{
	(void)stack_b;
	count_steps_a(stack_a);
	/* count_steps_b(stack_a, stack_b); */
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
