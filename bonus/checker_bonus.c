/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:41:52 by iassil            #+#    #+#             */
/*   Updated: 2025/01/28 08:02:18 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../_header/checker_bonus.h"

void	ft_apply_instruction(char *str, t_func *func,
	t_node **stack_a, t_node **stack_b)
{
	int		i;
	bool	flag;

	i = 0;
	flag = false;
	while (i <= 10)
	{
		if (ft_cmp(str, func[i].str, ft_strlen(str)) == 0
			&& ft_strlen(str) == ft_strlen(func[i].str))
		{
			func[i].inst(stack_a, stack_b);
			flag = true;
		}
		i++;
	}
	if (flag == false)
		(write(2, "Error\n", 6), exit(EXIT_FAILURE));
	else
		return ;
}

void	ft_collect_instruction(t_instruction **inst, t_func *func, char *ptr)
{
	int				i;
	int				flag;
	t_instruction	*new;

	i = 0;
	flag = 0;
	new = NULL;
	while (i <= 10)
	{
		if (ft_cmp(ptr, func[i].str, ft_strlen(ptr)) == 0
			&& ft_strlen(ptr) == ft_strlen(func[i].str))
		{
			new = (t_instruction *)malloc(sizeof(t_instruction));
			if (!new)
				(write(2, "Error\n", 6), exit(EXIT_FAILURE));
			new->content = ft_strdup(ptr);
			new->next = NULL;
			ft_add_back(inst, new);
			flag = true;
		}
		i++;
	}
	if (flag == false)
		(write(2, "Error\n", 6), free_inst(inst), exit(EXIT_FAILURE));
	return ;
}

static void	ft_execute_instructions(t_instruction *instructions,
	t_func *func, t_node **stack_a, t_node **stack_b)
{
	t_instruction	*temp;
	int				stack_a_len;

	temp = instructions;
	stack_a_len = ft_listlen(stack_a);
	while (temp)
	{
		ft_apply_instruction(temp->content, func, stack_a, stack_b);
		temp = temp->next;
	}
	if (ft_listlen(stack_a) == stack_a_len && ft_check_if_sorted(stack_a) == 0)
	{
		write(1, "OK\n", 3);
		ft_fnodes(stack_a);
		ft_fnodes(stack_b);
		free_inst(&instructions);
		exit(EXIT_SUCCESS);
	}
	else
	{
		write(1, "KO\n", 3);
		free_inst(&instructions);
		exit(EXIT_FAILURE);
	}
}

void	ft_checker(t_node **stack_a, t_node **stack_b)
{
	char			*ptr;
	t_func			func[11];
	t_instruction	*instructions;

	instructions = NULL;
	ft_fill_func(func, stack_a, stack_b);
	while (1)
	{
		ptr = get_next_line(STDIN_FILENO);
		if (!ptr)
			break ;
		(ft_collect_instruction(&instructions, func, ptr), free(ptr));
	}
	ft_execute_instructions(instructions, func, stack_a, stack_b);
}

int	main(int ac, char **av)
{
	int		i;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		exit(EXIT_SUCCESS);
	i = 1;
	while (i < ac)
	{
		ft_parse(av[i], &stack_a);
		i++;
	}
	ft_checker(&stack_a, &stack_b);
	ft_fnodes(&stack_a);
	return (0);
}
