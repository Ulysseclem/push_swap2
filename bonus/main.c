/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uclement <uclement@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:53:31 by uclement          #+#    #+#             */
/*   Updated: 2023/06/02 11:54:50 by uclement         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h>

void	apply_function(t_stack **a, t_stack **b, char *readed)
{
	if (ft_strncmp (readed, "sa\n", 3) == 0)
		pair_swap(a);
	else if (ft_strncmp (readed, "sb\n", 3) == 0)
		pair_swap(b);
	else if (ft_strncmp (readed, "pa\n", 3) == 0)
		push(a, b);
	else if (ft_strncmp (readed, "pb\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp (readed, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp (readed, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp (readed, "rra\n", 4) == 0)
		reverse(a);
	else if (ft_strncmp (readed, "rrb\n", 4) == 0)
		reverse(b);
}

t_stack	*create_stack(int content)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->content = content;
	stack->index = 0;
	stack->next = NULL;
	return (stack);
}

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

void	to_list_a(char **argv, int argc, t_stack **stack_a)
{
	long long int	nbr;
	t_stack			*new_node;
	int				i;

	i = 1;
	if (argc <= 2)
		error_exit();
	while (i < argc)
	{
		nbr = ps_atoi(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			error_exit();
		if (i == 1)
			*stack_a = create_stack(nbr);
		else
		{
			new_node = create_stack(nbr);
			ps_lstadd_front(stack_a, new_node);
		}
		i++;
	}
}

void	print_list(t_stack *stack)
{
	while (stack != NULL)
	{
		printf ("%d\n", stack->content);
		stack = stack->next;
	}
}

int	is_sort(t_stack *a)
{
	while (a->content > a->next->content)
	{
		a = a->next;
		if (a->next == NULL)
			return (0);
	}
	return (1);
}

int	main(int argc, char	**argv)
{
	char	*line;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;

	to_list_a(argv, argc, &stack_a);
	line = get_next_line(0);
	while (line)
	{
		apply_function(&stack_a, &stack_b, line);
		line = get_next_line(0);
	}
	print_list(stack_a);
	if (is_sort(stack_a) == 1)
		write (1, "ko", 2);
	else
		write (1, "ok", 2);
	return (0);
	free_lst(&stack_a);
}


	// t_stack	*stack_b;

	// stack_b = NULL;
	// to_list_a(argv, argc, &stack_a);
	// if (parsing(stack_a) == 0)
	// {
	// 	free_lst(&stack_a);
	// 	error_exit();
	// }
	// if (is_sort(stack_a) == 0)
	// {
	// 	free_lst(&stack_a);
	// 	return (0);
	// }
	// index_maker(&stack_a);
	// median_sort(&stack_a, &stack_b);
	// while (stack_b)
	// 	iter_index(&stack_a, &stack_b);
	// last_sort(&stack_a, &stack_b);
	// free_lst(&stack_a);
	// free_lst(&stack_b);
