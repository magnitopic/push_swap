/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:16:59 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/13 16:52:20 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = validator(argc, argv);
	stack_b = NULL;
	if (ft_issorted(stack_a, stack_b))
		return (0);
	if (argc < 6)
		ft_printf("%s", short_sort(stack_a, stack_b));
	else
		ft_printf("%s", modern_times(stack_a, stack_b));
	return (0);
}
