/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:16:59 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/22 19:18:36 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char **argv)
{
	t_list	*test_list;
	t_list	*node;
	int	i;
	int *string;

	i = 0;
	string = ft_calloc(ft_strlen)
	while (i < (int)ft_strlen(argv[1]))
	{
		string
	}
	= argv[1];
	test_list = ft_lstnew(&ft_atoi(string[i++]));
	while (i < (int)ft_strlen(string))
	{
		ft_lstadd_back(&test_list, ft_lstnew(&ft_atoi(string[i++]));
	}
	ft_lstprint_char(test_list);
}
