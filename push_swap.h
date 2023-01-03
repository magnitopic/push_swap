/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:21:47 by alaparic          #+#    #+#             */
/*   Updated: 2023/01/01 20:02:27 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <time.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		*random_stack(int amount);
void	ft_swap(int *stack_a, int a_size);
void	pa(int *stack_a, int *a_size, int *stack_b, int b_size);
void	pb(int *stack_b, int b_size, int *stack_a, int *a_size);
void	ft_rotate(int *stack_a, int *a_size);
void	ft_reverse_rotate(int *stack_a, int *a_size);
void	print_stacks(int *stack_a, int a_size, int *stack_b, int b_size);

#endif