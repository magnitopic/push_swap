/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:16:59 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/18 19:08:11 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "./libft/libft.h"

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

static int	*random_nums(int amount)
{
	int	*nums;
	int	i;
	int	rnd;

	i = 0;
	srand(time(NULL));
	nums = ft_calloc((amount + 1), sizeof(int));
	while (i < amount)
	{
		rnd = (rand() % (amount )) + 1;
		while (ft_contains(nums, rnd))
		{
			rnd = (rand() % (amount)) + 1;
		}
		nums[i] = rnd;
		i++;
	}
	return (nums);
}

int	main(void)
{
	int	*nums;

	nums = random_nums(6);
	while (*nums)
	{
		ft_printf("%d\n", *nums);
		nums++;
	}	
	return (0);
}
