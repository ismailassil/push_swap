/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:33:02 by iassil            #+#    #+#             */
/*   Updated: 2024/01/31 17:51:52 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/checker_bonus.h"

/* Swap the first 2 element at the top of Stack 'a' */
void	sa(t_node **stack_a, t_node **stack_b)
{
	t_node	*head;
	int		temp;

	(void)stack_b;
	if (ft_listlen(stack_a) <= 1 || *stack_a == NULL
		|| (*stack_a)->next == NULL)
		return ;
	head = *stack_a;
	temp = head->content;
	head->content = head->next->content;
	head->next->content = temp;
}

/* Swap the first 2 element at the top of Stack 'b' */
void	sb(t_node **stack_a, t_node **stack_b)
{
	t_node	*head;
	int		temp;

	(void)stack_a;
	if (ft_listlen(stack_b) <= 1 || *stack_b == NULL
		|| (*stack_b)->next == NULL)
		return ;
	head = *stack_b;
	temp = head->content;
	head->content = head->next->content;
	head->next->content = temp;
}

/* Swap the first 2 element at the top of Stack 'a' && 'b' */
void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a, stack_b);
	sb(stack_a, stack_b);
}
