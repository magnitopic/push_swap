/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:12:22 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/08 18:54:21 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*count_min_steps(t_list *stack_a, t_list *stack_b)
{
	int	*steps_a;
	int	*steps_b;

	steps_a = count_steps_a(stack_a);
	steps_b = count_steps_b(stack_a, stack_b);
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
		if (i < (lst_len / 2))
			n_steps[i] = i;
		else
			n_steps[i] = -(lst_len - i);
		i++;
	}
	return (n_steps);
}

int	count_steps_b(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	j;
	int	*n_steps;
	int	maxinf;

	n_steps = ft_calloc(ft_lstsize(stack_a), sizeof(int));
	while (i < ft_lstsize(stack_a))
	{
		
		/* maxinf = ft_lstmin(stack_b);
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
			n_steps[i] = -(lst_len - i); */
	}
}
