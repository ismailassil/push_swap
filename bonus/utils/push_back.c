/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 20:23:11 by iassil            #+#    #+#             */
/*   Updated: 2025/01/27 20:23:24 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/checker_bonus.h"

void	ft_add_back(t_instruction **lst, t_instruction *_new)
{
	t_instruction	*last;

	if (!*lst)
	{
		*lst = _new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = _new;
}

void	free_instructions(t_instruction **lst)
{
	t_instruction	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp->content);
		free(tmp);
	}
}
