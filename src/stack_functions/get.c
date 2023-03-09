/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:27:29 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/09 16:50:16 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*get(t_stack *stack, int pos)
{
	int		i;
	t_stack	*node;

	node = stack;
	i = 0;
	while (i < pos)
	{
		i++;
		node = node->next;
	}
	return (node);
}
