/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:16:59 by alaparic          #+#    #+#             */
/*   Updated: 2022/12/18 17:23:02 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

static int	*random_nums(int amount)
{
	int	*nums;

	nums = ft_calloc((amount + 1), sizeof(int));
	while (amount-- != 0)
	{
		nums[amount] = 5;
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
