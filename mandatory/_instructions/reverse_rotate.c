/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:32:31 by iassil            #+#    #+#             */
/*   Updated: 2024/01/30 15:28:17 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/push_swap.h"

/**	Shift down all elements of stack 'a' by 1,
*	The last element becomes the first one.*/
void	rra(t_node **stack_a, int flag)
{
	t_node	*head;
	t_node	*hold;

	if (ft_listlen(stack_a) <= 1 || stack_a == NULL || (*stack_a) == NULL)
		return ;
	if (flag == 1)
		write(1, "rra\n", 4);
	head = *stack_a;
	if (head->next == NULL)
		return ;
	while (head->next->next != NULL)
		head = head->next;
	hold = head->next;
	head->next = NULL;
	hold->next = *stack_a;
	*stack_a = hold;
}

/**	Shift down all elements of stack 'b' by 1,
*	The last element becomes the first one.*/
void	rrb(t_node **stack_b, int flag)
{
	t_node	*head;
	t_node	*hold;

	if (ft_listlen(stack_b) <= 1 || stack_b == NULL || (*stack_b) == NULL)
		return ;
	if (flag == 1)
		write(1, "rrb\n", 4);
	head = *stack_b;
	if (head->next == NULL)
		return ;
	while (head->next->next != NULL)
		head = head->next;
	hold = head->next;
	head->next = NULL;
	hold->next = *stack_b;
	*stack_b = hold;
}

/**	'rra' and 'rrb' at the same time,
*	The last element becomes the first one.*/
void	rrr(t_node **stack_a, t_node **stack_b)
{
	int	flag;

	flag = 0;
	write(1, "rrr\n", 4);
	rra(stack_a, flag);
	rrb(stack_b, flag);
}
