/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:03:02 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/25 17:19:18 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_issorted(t_list *stack_a, t_list *stack_b)
{
	int	i;
	int	len;

	if (ft_lstsize(stack_b))
		return (0);
	i = 1;
	len = ft_lstsize(stack_a);
	while (len > i)
	{
		if (ft_get(stack_a, i) > ft_get(stack_a, i - 1))
			return (0);
		i++;
	}
	return (1);
}
