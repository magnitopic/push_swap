/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:39:07 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/27 16:43:45 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	dict_add_back(t_entry **lst, t_entry *new)
{
	if (*lst == 0)
		*lst = new;
	else
	{
		while ((*lst)->next != 0)
				lst = &(*lst)->next;
			(*lst)->next = new;
	}
}
