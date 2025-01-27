/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:26:01 by iassil            #+#    #+#             */
/*   Updated: 2024/02/07 21:26:58 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/push_swap.h"

/*	Returns the max value in linked list	*/
int	ft_max_node(t_node **lst)
{
	t_node	*head;
	int		max;

	head = *lst;
	max = head->content;
	while (head != NULL)
	{
		if (max < head->content)
			max = head->content;
		head = head->next;
	}
	return (max);
}

/*	Sort the linked list of size 3 (nodes)	*/
void	ft_sort_tres(t_node **lst)
{
	int	max;

	max = ft_max_node(lst);
	if (max == (*lst)->content)
		ra(lst, 1);
	else if (max == (*lst)->next->content)
		rra(lst, 1);
	if ((*lst)->content > (*lst)->next->content)
		sa(lst, 1);
}

/*	Sort the linked list of size 4 (nodes)	*/
void	ft_sort_cuatro(t_node **stack_a, t_node **stack_b)
{
	int	max;

	max = ft_max_node(stack_a);
	if (max == (*stack_a)->next->content)
		sa(stack_a, 1);
	else if (max == (*stack_a)->next->next->content)
		(ra(stack_a, 1), sa(stack_a, 1));
	else if (max == (*stack_a)->next->next->next->content)
		rra(stack_a, 1);
	pb(stack_a, stack_b);
	ft_sort_tres(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a, 1);
}

/*	Sort the linked list of size 5 (nodes)	*/
void	ft_sort_cinco(t_node **stack_a, t_node **stack_b)
{
	int	max;

	max = ft_max_node(stack_a);
	if (max == (*stack_a)->next->content)
		sa(stack_a, 1);
	else if (max == (*stack_a)->next->next->content)
		(ra(stack_a, 1), sa(stack_a, 1));
	else if (max == (*stack_a)->next->next->next->content)
		(rra(stack_a, 1), rra(stack_a, 1));
	else if (max == (*stack_a)->next->next->next->next->content)
		rra(stack_a, 1);
	pb(stack_a, stack_b);
	ft_sort_cuatro(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a, 1);
}
