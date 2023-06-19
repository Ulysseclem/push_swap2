/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:34:14 by uclement          #+#    #+#             */
/*   Updated: 2023/06/19 13:36:22 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

char	*get_next_line(int fd);
void	to_line(char *stock, char **line);
void	read_stock(char **stock, int fd);
void	free_stock(char **stock);

int		check_newline(char *buf);
char	*gnl_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);

int		to_list_a(char **argv, int argc, t_stack **stack_a);
int		is_sort(t_stack *a);
void	error_exit(void);
t_stack	*create_stack(int content);

void	free_lst(t_stack	**lst);
void	apply_function(t_stack **a, t_stack **b, char *readed);
int		ps_lstsize(t_stack *lst);
t_stack	*ps_lstlast(t_stack *lst);
void	ps_lstadd_front(t_stack **lst, t_stack *new);

void	doublon(t_stack	*lst);
int		ps_atoi(const char *nptr, t_stack **a);
int		ps_atoi_suite(const char *nptr, int i, int neg, t_stack **a);

void	push(t_stack **receiver, t_stack **sender);
void	push_suite(t_stack **receiver, t_stack *curr);
void	rotate(t_stack **stack_a);
void	reverse(t_stack	**stack);
void	pair_swap(t_stack **stack);

#endif