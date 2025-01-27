/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:32:31 by iassil            #+#    #+#             */
/*   Updated: 2024/01/31 17:51:52 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/checker_bonus.h"

/**	Shift down all elements of stack 'a' by 1,
*	The last element becomes the first one.*/
void	rra(t_node **stack_a, t_node **stack_b)
{
	t_node	*head;
	t_node	*hold;

	(void)stack_b;
	if (ft_listlen(stack_a) <= 1 || stack_a == NULL || (*stack_a) == NULL)
		return ;
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
void	rrb(t_node **stack_a, t_node **stack_b)
{
	t_node	*head;
	t_node	*hold;

	(void)stack_a;
	if (ft_listlen(stack_b) <= 1 || stack_b == NULL || (*stack_b) == NULL)
		return ;
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
	rra(stack_a, stack_b);
	rrb(stack_a, stack_b);
}
