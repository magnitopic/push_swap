/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:52:22 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/09 17:22:41 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*add_new(t_stack *stack, int value)
{
	t_stack	*new_node;
	t_stack	*last_node;
	int		i;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->pasos_a = 0;
	new_node->pasos_b = 0;
	new_node->next = NULL;
	if (!stack)
		return (new_node);
	i = 0;
	last_node = stack;
	while (last_node->next != 0)
		last_node = last_node->next;
	last_node->next = new_node;
	return (stack);
}
