/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:02:33 by iassil            #+#    #+#             */
/*   Updated: 2024/01/30 15:28:55 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/push_swap.h"

void	ft_lstadd_back(t_node **lst, t_node *_new)
{
	t_node	*ptr;

	if (lst == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = _new;
		return ;
	}
	ptr = *lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = _new;
}
