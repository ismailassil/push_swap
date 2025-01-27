/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:39:53 by iassil            #+#    #+#             */
/*   Updated: 2024/01/30 15:28:55 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/push_swap.h"

void	ft_lstadd_front(t_node **lst, t_node *_new)
{
	if (lst == NULL)
		*lst = _new;
	else
	{
		_new->next = *lst;
		*lst = _new;
	}
}
