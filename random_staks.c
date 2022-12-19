/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_staks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:23:34 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/19 16:17:42 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int *array, int value)
{
	int	flag;

	flag = 0;
	while (*array)
	{
		if (*array++ == value)
			flag = 1;
	}
	return (flag);
}

int	*random_stack(int amount)
{
	int	*nums;
	int	i;
	int	rnd;

	i = 0;
	srand(time(NULL));
	nums = ft_calloc((amount + 1), sizeof(int));
	while (i < amount)
	{
		rnd = (rand() % (amount)) + 1;
		while (ft_contains(nums, rnd))
		{
			rnd = (rand() % (amount)) + 1;
		}
		nums[i] = rnd;
		i++;
	}
	return (nums);
}
