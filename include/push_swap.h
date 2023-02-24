/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaparic <alaparic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 19:21:47 by alaparic          #+#    #+#             */
/*   Updated: 2023/02/24 19:19:31 by alaparic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <time.h>
# include <stdlib.h>
# include "../libft/libft.h"

// Operations
char	*sa(t_list **stack_a, t_list **stack_b);
char	*sb(t_list **stack_a, t_list **stack_b);
char	*ss(t_list **stack_a, t_list **stack_b);
char	*pa(t_list **stack_a, t_list **stack_b);
char	*pb(t_list **stack_a, t_list **stack_b);
char	*ra(t_list **stack_a, t_list **stack_b);

#endif