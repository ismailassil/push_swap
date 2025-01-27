/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:41:52 by iassil            #+#    #+#             */
/*   Updated: 2024/02/08 13:13:39 by iassil           ###   ########.fr       */
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

void	ft_checker(t_node **stack_a, t_node **stack_b)
{
	char	*ptr;
	int		stack_a_len;
	t_func	func[11];	

	ft_fill_func(func, stack_a, stack_b);
	stack_a_len = ft_listlen(stack_a);
	while (1)
	{
		ptr = get_next_line(STDIN_FILENO);
		if (!ptr)
			break ;
		ft_apply_instruction(ptr, func, stack_a, stack_b);
		free(ptr);
	}
	if (ft_listlen(stack_a) == stack_a_len && ft_check_if_sorted(stack_a) == 0)
		(write(1, "OK\n", 3),
			ft_fnodes(stack_a), ft_fnodes(stack_b), exit(EXIT_SUCCESS));
	else
		(write(1, "KO\n", 3), exit(EXIT_SUCCESS));
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
