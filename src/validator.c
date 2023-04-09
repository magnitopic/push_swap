/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:47:14 by alaparic          #+#    #+#             */
/*   Updated: 2023/04/09 17:23:08 by alaparic         ###   ########.fr       */
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
		while (j < len)
		{
			if (get(stack_a, i)->value == get(stack_a, j)->value)
			{
				free_stacks(&stack_a);
				(ft_putstr_fd("\033[0;31mError\n\033[0m", 2), exit(-1));
			}
			j++;
		}
		i++;
	}
}

static t_stack	*create_stack(char **numbers)
{
	t_stack		*stack_a;
	int			i;
	long int	aux;

	stack_a = NULL;
	i = 0;
	while (numbers[i] != NULL)
	{
		aux = ft_atoi(numbers[i++]);
		if (aux > 214748367 || aux < -214748368)
		{
			free_matrix(numbers);
			(ft_putstr_fd("\033[0;31mError\n\033[0m", 2), exit(-1));
		}
		add_new(&stack_a, aux);
	}
	free_matrix(numbers);
	return (stack_a);
}

static char	*parser(char **val)
{
	int		i;
	int		j;
	char	*lst;

	i = 0;
	lst = calloc(1, 1);
	while (val[i] != NULL)
	{
		j = 0;
		if ((val[i][0] == '-' || val[i][0] == '+')
			&& ft_strlen(val[i]) > 1)
			j++;
		while (val[i][j] != '\0')
		{
			if (!ft_isdigit(val[i][j]))
			{
				free_matrix(val);
				(ft_putstr_fd("\033[0;31mError\n\033[0m", 2), exit(-1));
			}
			j++;
		}
		lst = ft_fstrjoin(ft_fstrjoin(lst, val[i++]), " ");
	}
	free_matrix(val);
	return (lst);
}

t_stack	*validator(int argc, char **argv)
{
	char	*lst;
	t_stack	*stack_a;
	int		i;
	char	*parsed;

	if (argc <= 1)
		return (NULL);
	lst = calloc(1, 1);
	i = 1;
	while (i < argc)
	{
		if (!ft_strlen(argv[i]))
			(ft_putstr_fd("\033[0;31mError\n\033[0m", 2), exit(-1));
		parsed = parser(ft_split(argv[i++], ' '));
		lst = ft_fstrjoin(lst, parsed);
		free(parsed);
	}
	stack_a = create_stack(ft_split(lst, ' '));
	free(lst);
	no_repeating_values(stack_a, stack_size(stack_a));
	return (stack_a);
}
