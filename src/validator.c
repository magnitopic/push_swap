/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:47:14 by alaparic          #+#    #+#             */
/*   Updated: 2023/03/11 19:17:28 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	no_repeating_values(t_stack *stack_a, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len - 1)
		{
			if (get(stack_a, i)->value == get(stack_a, j)->value)
				(ft_printf("\033[0;31mError\n\033[0m"), exit(-1));
			j++;
		}
		i++;
	}
}

static t_stack	*create_stack(char **numbers, int len)
{
	t_stack	*stack_a;
	int		i;
	int		*aux;

	stack_a = NULL;
	i = 0;
	aux = malloc(sizeof(int));
	*aux = ft_atoi(numbers[i++]);
	stack_a = add_new(stack_a, *aux);
	while (i < len)
	{
		aux = malloc(sizeof(int));
		*aux = ft_atoi(numbers[i++]);
		add_new(stack_a, *aux);
	}
	return (stack_a);
}

static char	*parser(int argc, char **argv)
{
	char	*value;
	char	*lst;
	int		i;

	i = 1;
	lst = "";
	while (i < argc)
	{
		value = ft_strtrim(argv[i++], " ");
		if (!ft_strlen(value))
			(ft_printf("\033[0;31mError\n\033[0m"), exit(-1));
		lst = ft_strjoin(ft_strjoin(lst, value), " ");
	}
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
	return (lst);
}

t_stack	*validator(int argc, char **argv)
{
	char	*lst;
	t_stack	*stack_a;

	if (argc <= 1)
		return (NULL);
	lst = parser(argc, argv);
	stack_a = create_stack(ft_split(lst, ' '), argc - 1);
	no_repeating_values(stack_a, argc - 1);
	return (stack_a);
}
