/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:02 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/03 17:31:08 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_issorted(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	len;
	int	first_value;
	int	second_value;

	if (ft_lstsize(stack_b) != 0)
		return (0);
	i = 0;
	len = ft_lstsize(stack_a);
	while ((len - 1) > i)
	{
		first_value = *(int *)ft_get(stack_a, i)->content;
		second_value = *(int *)ft_get(stack_a, i + 1)->content;
		if (first_value > second_value)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_in_function(t_entry *dict, t_list *stack_a, t_list *stack_b)
{
	int	i;

	i = 0;
	while (i < dict_size(dict))
	{
		/* ft_printf("i: %d\nvalue: %d\n",i ,ft_lstcompare(dict_get(dict, i)->stack_a, stack_a));
		ft_lstprint_int(dict_get(dict, i)->stack_a);
		ft_lstprint_int(stack_a);º */
		if (ft_lstcompare(dict_get(dict, i)->stack_a, stack_a)
			&& ft_lstcompare(dict_get(dict, i)->stack_b, stack_b))
			return (0);
		i++;
	}
	return (1);
}
