/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:47:14 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/11 15:14:15 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	**parse_input(int argc, char **argv)
{
	int		i;
	char	*lst;

	i = 1;
	lst = "";
	while (i < argc)
		lst = ft_strjoin(ft_strjoin(lst, argv[i++]), " ");
	i = 0;
	while ((size_t)i < ft_strlen(lst))
	{
		if (!ft_isdigit(lst[i])
			&& !((lst[i] == 43 || lst[i] == 45) && ft_isdigit(lst[i + 1]) \
			&& lst[i - 1] == 32)
			&& lst[i] != 32)
			(ft_printf("\033[0;31mError\n\033[0m"), exit(-1));
		i++;
	}
	return (ft_split(lst, ' '));
}

t_stack	*validator(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;
	int		*aux;
	char	**numbers;

	stack_a = NULL;
	if (argc <= 1)
		return (stack_a);
	numbers = parse_input(argc, argv);
	i = 0;
	aux = malloc(sizeof(int));
	*aux = ft_atoi(numbers[i++]);
	stack_a = add_new(stack_a, *aux);
	while (i < argc)
	{
		aux = malloc(sizeof(int));
		*aux = ft_atoi(numbers[i++]);
		add_new(stack_a, *aux);
	}
	return (stack_a);
}

/* int	main(int argc, char **argv)
{
	int i = 0;
	char **matrix = parse_input(argc, argv);
	while (i < 5)
	{
		ft_printf("%s", matrix[i]);
		i++;
	}
	return (0);
} */
