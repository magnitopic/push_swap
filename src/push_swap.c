/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:16:59 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/23 16:28:29 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_list *test_list;
	int i;
	int	aux;

	i = 1;
	/* ft_printf("%d", i); */
	aux = ft_atoi(argv[i++]);
	test_list = ft_lstnew(&aux);
	while (i < argc)
	{
		ft_printf("%d ",  *(int *)(test_list -> content));
		ft_printf("aux: %d\n", i);
		aux = ft_atoi(argv[i++]);
		ft_lstadd_back(&test_list, ft_lstnew(&aux));
	}
	ft_printf("%d ",  *(int *)(test_list -> content));
	ft_lstprint_int(test_list);
}
