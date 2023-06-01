/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:28:29 by uclement          #+#    #+#             */
/*   Updated: 2023/06/01 11:34:06 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include "libft.h"

typedef struct s_function
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}	t_instruct;

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}					t_stack;

void	pair_swap(t_stack **stack);
void	print_stack(t_stack *a, t_stack *b);
void	to_list_a(char **argv, int argc, t_stack **stack_a);
void	error_exit(void);
void	push(t_stack **receiver, t_stack **sender);
void	rotate(t_stack **stack_a);
void	reverse(t_stack	**stack);

void	free_lst(t_stack	**lst);

int		parsing(t_stack	*lst);

void	move(t_stack **stack_a, t_stack **stack_b, int call);
void	move_2(t_stack **stack_a, t_stack **stack_b, int call);
void	print_move(int call);

void	index_maker(t_stack **stack);
void	median_sort(t_stack **a, t_stack **b);
void	three(t_stack **a, t_stack **b);
void	five(t_stack **a, t_stack **b);
void	last_sort(t_stack **stack, t_stack **b);

void	find_pos(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b, int count);

void	compteur(t_instruct *count, int call);
void	calculateur(t_stack **b, int call);
void	search_index_min(t_stack **a, t_stack **b);
void	iter_index(t_stack **a, t_stack **b);
void	index_find_pos(t_stack **a, t_stack **b);
void	index_sort(t_stack **a, t_stack **b, int count);
void	sort_b_stack(t_stack **a, t_stack **b, int min);

void	double_move(t_stack **stack_a, t_stack **stack_b, int call);

int		is_sort(t_stack *a);

long long int	ps_atoi(const char *nptr);

void	push_suite(t_stack **receiver, t_stack *curr);
int		iter_i_min(t_stack **b, int min);

t_stack	*create_stack(int content);

void	median_rest(t_stack **a, t_stack **b);

void	last_sort_suite(t_stack **stack, t_stack **b, int count);

int	ps_lstsize(t_stack *lst);

void	ps_lstadd_front(t_stack **lst, t_stack *new);

t_stack	*ps_lstlast(t_stack *lst);

#endif