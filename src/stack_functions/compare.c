/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 16:32:22 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/10 17:00:03 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	compare(t_stack *lst1, t_stack *lst2)
{
	int	i;

	if (stack_size(lst1) != stack_size(lst2))
		return (0);
	i = 0;
	while (i <stack_size(lst1))
	{
		if (get(lst1, i)->value
			!= get(lst2, i)->value)
			return (0);
		i++;
	}
	return (1);
}
