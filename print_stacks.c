/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 13:57:09 by alaparic          #+#    #+#             */
/*   Updated: 2023/01/01 14:20:20 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(int *stack_a, int a_size, int *stack_b, int b_size)
{
	int	i;

	i = 0;
	while (i < a_size)
		ft_printf("%d, ", stack_a[i++]);
	ft_printf("\n");
	i = 0;
	while (i < b_size)
		ft_printf("%d, ", stack_b[i++]);
	ft_printf("\n");
}