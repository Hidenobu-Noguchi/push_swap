/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/20 16:10:54 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	make_circle_list(t_bidrect_circle_list *stack_a
		, t_bidrect_circle_list *last_node)
{
	t_bidrect_circle_list	*sentinel;

	sentinel = create_node(0, SENTINEL);
	if (!sentinel)
	{
		stack_clear(&last_node);
		stack_clear(&stack_a);
		exit_write_message(Malloc_error);
	}
	last_node->next = sentinel;
	sentinel->next = stack_a;
	stack_a->prev = sentinel;
	sentinel->prev = last_node;
}

void	connect_node(t_bidrect_circle_list *present_node
		, t_bidrect_circle_list *new_node)
{
	present_node->next = new_node;
	new_node->prev = present_node;
	/*
	t_bidrect_circle_list	*sentinel;
	t_bidrect_circle_list	*last_node;

	if (!new_node)
	{
		return ;
	}
	if (stack[0]->role == SENTINEL)
	{
		new_node->next = stack[0];
		stack[0]->prev = new_node;
	}
	else
	{
		last_node = stack_last(stack[0]);
		last_node->next = new;
		new->prev = last_node;
	}
	*/
}

t_bidrect_circle_list	*create_stack_a(int argc, char **argv)
{
	int						i;
	t_bidrect_circle_list	*new_node;
	t_bidrect_circle_list	*stack_a;
	t_bidrect_circle_list	*present_node;

	i = 2;
	stack_a = create_node(ft_atoi(argv[1]), NODE);
	present_node = stack_a;
	if (!stack_a)
	{
		exit_write_message(Malloc_error);
	}
	while (i < argc)
	{
		new_node = NULL;
		new_node = create_node(ft_atoi(argv[i]), NODE);
		if (!new_node)
		{
			stack_clear(&stack_a);
			exit_write_message(Malloc_error);
		}
		connect_node(present_node, new_node);
		present_node = new_node;
		i += 1;
	}
	make_circle_list(stack_a, present_node);
	return (stack_a);
}

/*
t_stack	*create_stack_a(int argc, char **argv)
{
	int		i;
	t_stack	*new_node;
	t_stack	*stack_a;

	i = 1;
	new_node = NULL;
	stack_a = NULL;
	while (i < argc)
	{
		new_node = create_node(ft_atoi(argv[i]));
		if (!new_node)
		{
			stack_clear(&stack_a);
			exit_write_message(Malloc_error);
		}
		add_node_stack_back(&stack_a, new_node);
		i += 1;
	}
	return (stack_a);
}
*/
/*
int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	if (!(stack_a = create_stack_a(argc, argv)))
	{
		exit_write_message("Error\n");
	}
	i = 0;
	while (stack_a->next)
	{
		printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
		stack_a = stack_a->next;
		i += 1;

	}
	printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
	stack_clear(&stack_a);
	// execute_push_swap
	//
	system("leaks -q push_swap");
	return (0);
}
*/
