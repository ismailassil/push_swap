/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:33:02 by iassil            #+#    #+#             */
/*   Updated: 2024/01/30 15:28:21 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/push_swap.h"

/* Swap the first 2 element at the top of Stack 'a' */
void	sa(t_node **stack_a, int flag)
{
	t_node	*head;
	int		temp;

	if (ft_listlen(stack_a) <= 1 || *stack_a == NULL
		|| (*stack_a)->next == NULL)
		return ;
	head = *stack_a;
	if (flag == 1)
		write(1, "sa\n", 3);
	temp = head->content;
	head->content = head->next->content;
	head->next->content = temp;
}

/* Swap the first 2 element at the top of Stack 'b' */
void	sb(t_node **stack_b, int flag)
{
	t_node	*head;
	int		temp;

	if (ft_listlen(stack_b) <= 1 || *stack_b == NULL
		|| (*stack_b)->next == NULL)
		return ;
	if (flag == 1)
		write(1, "sb\n", 3);
	head = *stack_b;
	temp = head->content;
	head->content = head->next->content;
	head->next->content = temp;
}

/* Swap the first 2 element at the top of Stack 'a' && 'b' */
void	ss(t_node **stack_a, t_node **stack_b)
{
	int	flag;

	flag = 0;
	write(1, "ss\n", 3);
	sa(stack_a, flag);
	sb(stack_b, flag);
}
