/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:16:59 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/01 21:06:26 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_entry	*dict;
	char	*moves;

	stack_a = validator(argc, argv);
	stack_b = NULL;
	if (ft_issorted(stack_a, stack_b))
		return (0);
	if (argc <= 6)
	{
		dict = short_sort(stack_a, stack_b);
		moves = dict_get(dict, dict_size(dict) - 1)->moves;
		//free_dict();
	}
	else
		moves = modern_times(&stack_a, &stack_b);
	ft_printf("%s", moves);
	free(moves);
	return (0);
}
