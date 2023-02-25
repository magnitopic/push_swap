/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_staks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:23:34 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/25 15:49:55 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

static int	ft_contains(int *array, int value)
{
	while (*array)
	{
		if (*array++ == value)
			return (1);
	}
	return (0);
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
		rnd = (rand() % (201) + 1);
		while (ft_contains(nums, rnd))
		{
			rnd = (rand() % (201) + 1);
		}
		nums[i] = rnd;
		i++;
	}
	i = 0;
	while (i < amount)
		nums[i++] -= 101;
	return (nums);
}

int	main(void)
{
	int	*nums;

	nums = random_stack(10);
	while (*nums)
	{
		ft_printf("%d ", *nums);
		nums++;
	}
	return (0);
}
