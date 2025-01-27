/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:43:26 by iassil            #+#    #+#             */
/*   Updated: 2024/02/04 21:32:37 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../_header/push_swap.h"

/*	Free the Linked List	*/
void	ft_fnodes(t_node **head)
{
	t_node	*lst;
	t_node	*tobefreed;

	lst = *head;
	tobefreed = NULL;
	while (lst != NULL)
	{
		tobefreed = lst;
		lst = lst->next;
		free(tobefreed);
	}
}

/*	Check for Duplicate Numbers	*/
int	ft_check_duplicate(t_node **lst, t_node *temp)
{
	t_node	*head;
	int		current;

	head = *lst;
	if (head == NULL)
		return (0);
	current = temp->content;
	while (head != NULL)
	{
		if (head->content == current)
			return (1);
		head = head->next;
	}
	return (0);
}

/*	Check if the Numbers are correctly entered	*/
int	ft_check_arg(char *str)
{
	int		i;
	bool	flag;

	i = 0;
	flag = false;
	if (ft_strlen(str) == 1 && (str[0] == '-' || str[0] == '+'))
		return (1);
	while (str[i] == '-' || str[i] == '+')
		i++;
	if (i >= 2)
		return (1);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		if (ft_isdigit(str[i]) == 1)
			flag = true;
		i++;
	}
	if (flag == false)
		return (1);
	return (0);
}

/*	Create a Node and link it to the linked list	*/
void	ft_create_node(char *str, t_node **head)
{
	long	temp;
	t_node	*temp_node;

	if (ft_check_arg(str) == 1)
		(write(2, "Error\n", 7), ft_fnodes(head), exit(EXIT_FAILURE));
	temp = ft_atoi(str);
	if (temp == 2147483649)
		(write(2, "Error\n", 7), ft_fnodes(head), exit(EXIT_FAILURE));
	temp_node = ft_lstnew(temp);
	if (ft_check_duplicate(head, temp_node) == 1)
		(write(2, "Error: DUPLICATE NUMBER!\n", 25),
			ft_fnodes(head), free(temp_node), exit(EXIT_FAILURE));
	ft_lstadd_back(head, temp_node);
}

/*	Where all the functions are linked here	*/
void	ft_parse(char *str, t_node **head)
{
	t_parse	info;

	info.i = 0;
	info.flag = false;
	while (str[info.i] != '\0')
	{
		if (str[info.i++] == ' ')
			info.flag = true;
	}
	if (info.flag == true)
	{
		info.ptr = ft_split(str, ' ');
		if (info.ptr == NULL || info.ptr[0] == NULL)
			(write(2, "Error\n", 7), free(info.ptr),
				ft_fnodes(head), exit(EXIT_FAILURE));
		info.i = 0;
		while (info.ptr[info.i] != NULL)
		{
			ft_create_node(info.ptr[info.i], head);
			free(info.ptr[info.i++]);
		}
		free(info.ptr);
	}
	else
		ft_create_node(str, head);
}
