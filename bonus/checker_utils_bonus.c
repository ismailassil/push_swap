/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:52:03 by iassil            #+#    #+#             */
/*   Updated: 2024/01/31 19:26:01 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_header/checker_bonus.h"

void	ft_fill_func(t_func *func, t_node **stack_a, t_node **stack_b)
{
	func[0] = (t_func){"sa\n", stack_a, stack_b, sa};
	func[1] = (t_func){"sb\n", stack_a, stack_b, sb};
	func[2] = (t_func){"ss\n", stack_a, stack_b, ss};
	func[3] = (t_func){"pa\n", stack_a, stack_b, pa};
	func[4] = (t_func){"pb\n", stack_a, stack_b, pb};
	func[5] = (t_func){"ra\n", stack_a, stack_b, ra};
	func[6] = (t_func){"rb\n", stack_a, stack_b, rb};
	func[7] = (t_func){"rr\n", stack_a, stack_b, rr};
	func[8] = (t_func){"rra\n", stack_a, stack_b, rra};
	func[9] = (t_func){"rrb\n", stack_a, stack_b, rrb};
	func[10] = (t_func){"rrr\n", stack_a, stack_b, rrr};
}

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
