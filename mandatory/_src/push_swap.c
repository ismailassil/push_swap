/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:24:13 by iassil            #+#    #+#             */
/*   Updated: 2025/01/27 20:29:04 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
		exit(EXIT_SUCCESS);
	i = 1;
	while (i < ac)
	{
		ft_parse(av[i], &stack_a);
		i++;
	}
	ft_index_nodes(&stack_a);
	ft_algorithm(&stack_a, &stack_b);
	ft_fnodes(&stack_a);
	return (0);
}
