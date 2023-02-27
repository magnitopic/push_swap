/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:16:46 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/27 17:45:53 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_entry	*dict_get(t_entry *dict, int pos)
{
	int		i;
	t_entry	*node;

	node = dict;
	i = 0;
	while (i < pos)
	{
		i++;
		node = node->next;
	}
	return (node);
}
