/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:51:26 by iassil            #+#    #+#             */
/*   Updated: 2025/01/27 20:24:10 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "../bonus/get_next_line/get_next_line_bonus.h"

typedef struct s_node
{
	int				content;
	struct s_node	*next;
}					t_node;

typedef struct s_instruction
{
	char					*content;
	struct s_instruction	*next;
}							t_instruction;

typedef struct s_func
{
	char	*str;
	t_node	**stack_a;
	t_node	**stack_b;
	void	(*inst)(t_node **, t_node **);
}			t_func;

typedef struct s_parse
{
	int		i;
	bool	flag;
	char	**ptr;
}			t_parse;

/** Linked List instructions **/
void	ft_add_back(t_instruction **lst, t_instruction *_new);
void	free_instructions(t_instruction **lst);
void	ft_collect_instruction(t_instruction **inst, t_func *func, char *ptr);

/** Linked List functions **/
t_node	*ft_lstnew(int content);
void	ft_lstadd_back(t_node **lst, t_node *_new);
void	ft_lstadd_front(t_node **lst, t_node *_new);
void	ft_create_node(char *str, t_node **head);
/** Parsing functions **/
void	ft_parse(char *str, t_node **head);
void	ft_create_node(char *str, t_node **head);
int		ft_check_duplicate(t_node **lst, t_node *temp);
int		ft_check_arg(char *str);
void	ft_fnodes(t_node **head);
/**	Checker functions	**/
void	ft_fill_func(t_func *func, t_node **stack_a, t_node **stack_b);
void	ft_checker(t_node **stack_a, t_node **stack_b);
void	ft_apply_instruction(char *str, t_func *func,
			t_node **stack_a, t_node **stack_b);
/** Sorting functions **/
int		ft_check_if_sorted(t_node **stack_a);
/** Utils functions **/
int		ft_listlen(t_node **lst);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_cmp(char *s1, char *s2, size_t n);
long	ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen_(char const *str);
/** Instructions **/
void	sa(t_node **stack_a, t_node **stack_b);
void	sb(t_node **stack_a, t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a, t_node **stack_b);
void	rb(t_node **stack_a, t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a, t_node **stack_b);
void	rrb(t_node **stack_a, t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);

#endif
