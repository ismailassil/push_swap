/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iassil <iassil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 23:49:54 by iassil            #+#    #+#             */
/*   Updated: 2024/02/08 13:09:11 by iassil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	int				content;
	int				index;
	int				position;
	struct s_node	*next;
}					t_node;

typedef struct s_info
{
	int		max;
	int		min;
	int		index;
	t_node	*head;
}			t_info;

typedef struct s_parse
{
	int		i;
	bool	flag;
	char	**ptr;
}			t_parse;

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
/** Sorting functions **/
int		ft_check_if_sorted(t_node **stack_a);
void	ft_algorithm(t_node **stack_a, t_node **stack_b);
void	ft_from_a_to_b(t_node **stack_a, t_node **stack_b);
void	ft_from_b_to_a(t_node **stack_a, t_node **stack_b);
void	ft_sort_tres(t_node **lst);
void	ft_sort_cuatro(t_node **stack_a, t_node **stack_b);
void	ft_sort_cinco(t_node **stack_a, t_node **stack_b);
void	ft_index_nodes(t_node **lst);
/** Utils functions **/
void	ft_listposition(t_node **lst);
int		ft_max_position(t_node **lst);
int		ft_min_position(t_node **lst);
int		ft_listlen(t_node **lst);
int		ft_max_node(t_node **lst);
long	ft_atoi(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
int		ft_isdigit(int c);
char	*ft_strdup(const char *s1);
int		ft_isalpha(int c);
/** Instructions **/
void	sa(t_node **stack_a, int flag);
void	sb(t_node **stack_b, int flag);
void	ss(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a, int flag);
void	rb(t_node **stack_b, int flag);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a, int flag);
void	rrb(t_node **stack_b, int flag);
void	rrr(t_node **stack_a, t_node **stack_b);

#endif
