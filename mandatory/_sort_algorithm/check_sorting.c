/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:16:14 by iassil            #+#    #+#             */
/*   Updated: 2024/02/04 21:38:10 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/push_swap.h"

/*	Checks whether the linked list is sorted or not	*/
int	ft_check_if_sorted(t_node **stack_a)
{
	t_node	*head;

	if (*stack_a == NULL)
		return (1);
	head = *stack_a;
	while (head->next != NULL)
	{
		if (head->content > head->next->content)
			return (1);
		head = head->next;
	}
	return (0);
}

/*	Index the node from it's value
*	(the lowest value has the lowest index)
*/
void	ft_index_nodes(t_node **lst)
{
	t_node	*head;
	t_node	*tmp;

	head = *lst;
	while (head != NULL)
	{
		tmp = *lst;
		head->index = 0;
		while (tmp != NULL)
		{
			if (head->content > tmp->content)
				head->index++;
			tmp = tmp->next;
		}
		head = head->next;
	}
}

/*	List each node with it's position in linked list	*/
void	ft_listposition(t_node **lst)
{
	t_info	info;
	int		i;

	if (lst == NULL || (*lst) == NULL)
		return ;
	i = 0;
	info.head = *lst;
	while (info.head != NULL)
	{
		info.head->position = i;
		info.head = info.head->next;
		i++;
	}
}

/*	Returns the position of the max index from the linked list	*/
int	ft_max_position(t_node **lst)
{
	t_node	*head;
	int		max;
	int		position;

	if (lst == NULL || (*lst) == NULL)
		return (0);
	head = *lst;
	max = (*lst)->index;
	position = (*lst)->position;
	while (head != NULL)
	{
		if (max < head->index)
		{
			max = head->index;
			position = head->position;
		}
		head = head->next;
	}
	return (position);
}
