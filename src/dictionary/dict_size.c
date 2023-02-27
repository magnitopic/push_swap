/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:24:06 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/27 16:27:47 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	dict_size(t_entry *dictionary)
{
	int	len;

	len = 1;
	if (dictionary)
	{
		while (dictionary->next != 0)
		{
			dictionary = dictionary->next;
			len++;
		}
		return (len);
	}
	return (0);
}
