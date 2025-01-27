/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:30:49 by iassil            #+#    #+#             */
/*   Updated: 2024/02/05 12:26:42 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/push_swap.h"

/* Take the first element at the top of 'b' and put it at the top of 'a' */
void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*hold;

	if (stack_b == NULL || (*stack_b) == NULL)
		return ;
	write(1, "pa\n", 3);
	hold = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	ft_lstadd_front(stack_a, hold);
}

/* Take the first element at the top of 'a' and put it at the top of 'b' */
void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*hold;

	if (stack_a == NULL || (*stack_a) == NULL)
		return ;
	write(1, "pb\n", 3);
	hold = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	ft_lstadd_front(stack_b, hold);
}
