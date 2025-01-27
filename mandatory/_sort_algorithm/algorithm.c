/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:12:59 by iassil            #+#    #+#             */
/*   Updated: 2024/02/07 21:21:57 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/push_swap.h"

int	ft_listlen(t_node **lst)
{
	t_node	*head;
	int		count;

	count = 0;
	if (lst == NULL || (*lst) == NULL)
		return (count);
	head = *lst;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

void	ft_easy_sort(t_node **stack_a, t_node **stack_b, int len)
{
	if (len == 1)
		exit(EXIT_SUCCESS);
	if (len == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a, 1);
	}
	if (len == 3)
		ft_sort_tres(stack_a);
	if (len == 4)
		ft_sort_cuatro(stack_a, stack_b);
	if (len == 5)
		ft_sort_cinco(stack_a, stack_b);
}

void	ft_algorithm(t_node **stack_a, t_node **stack_b)
{
	int	len;

	if (ft_check_if_sorted(stack_a) == 0)
		exit(EXIT_SUCCESS);
	len = ft_listlen(stack_a);
	if (len <= 5)
		ft_easy_sort(stack_a, stack_b, len);
	else
	{
		ft_from_a_to_b(stack_a, stack_b);
		ft_from_b_to_a(stack_a, stack_b);
	}
	if (ft_check_if_sorted(stack_a) == 0 && len == ft_listlen(stack_a))
		(ft_fnodes(stack_a), exit(EXIT_SUCCESS));
}

void	ft_from_a_to_b(t_node **stack_a, t_node **stack_b)
{
	int	range;
	int	i;

	i = 0;
	if (ft_listlen(stack_a) > 100)
		range = 33;
	else
		range = 16;
	while (ft_listlen(stack_a))
	{
		if ((*stack_a)->index <= i)
			(pb(stack_a, stack_b), i++);
		else if ((*stack_a)->index < (i + range))
		{
			pb(stack_a, stack_b);
			rb(stack_b, 1);
			i++;
		}
		else
			ra(stack_a, 1);
	}
}

void	ft_from_b_to_a(t_node **stack_a, t_node **stack_b)
{
	int	max_pos;
	int	len;

	len = ft_listlen(stack_b);
	ft_listposition(stack_b);
	max_pos = ft_max_position(stack_b);
	while (*stack_b)
	{
		if (max_pos == 0)
			pa(stack_a, stack_b);
		else if (max_pos > (len / 2))
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
		ft_listposition(stack_b);
		max_pos = ft_max_position(stack_b);
		len = ft_listlen(stack_b);
	}
}
