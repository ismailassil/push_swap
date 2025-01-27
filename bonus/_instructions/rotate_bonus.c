/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:30:32 by iassil            #+#    #+#             */
/*   Updated: 2024/01/31 17:51:52 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/checker_bonus.h"

/*	Shift up all elements of stack 'a' by 1,
*	The first element becomes the last one.*/
void	ra(t_node **stack_a, t_node **stack_b)
{
	t_node	*hold;
	t_node	*head;

	(void)stack_b;
	if (ft_listlen(stack_a) <= 1 || stack_a == NULL || (*stack_a) == NULL)
		return ;
	hold = *stack_a;
	head = *stack_a;
	while (head->next != NULL)
		head = head->next;
	*stack_a = (*stack_a)->next;
	head->next = hold;
	hold->next = NULL;
}

/*	Shift up all elements of stack 'b' by 1,
*	The first element becomes the last one.*/
void	rb(t_node **stack_a, t_node **stack_b)
{
	t_node	*hold;
	t_node	*head;

	(void)stack_a;
	if (ft_listlen(stack_b) <= 1 || stack_b == NULL || (*stack_b) == NULL)
		return ;
	hold = *stack_b;
	head = *stack_b;
	while (head->next != NULL)
		head = head->next;
	*stack_b = (*stack_b)->next;
	head->next = hold;
	hold->next = NULL;
}

/*	'ra' and 'rb' at the same time,
*	The first element becomes the last one.*/
void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a, stack_b);
	rb(stack_a, stack_b);
}
