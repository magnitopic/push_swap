/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:25:52 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/09 17:27:47 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	stack_size(t_stack *stack)
{
	int	len;

	len = 1;
	if (stack)
	{
		while (stack->next != 0)
		{
			stack = stack->next;
			len++;
		}
		return (len);
	}
	return (0);
}