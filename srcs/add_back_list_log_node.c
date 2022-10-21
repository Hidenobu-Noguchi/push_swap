/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back_list_log_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/21 17:19:42 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_operation_log_list	*search_list_last_node(t_operation_log_list *list)
{
	if (!list)
	{
		return (NULL);
	}
	while (list->next)
	{
		list = list->next;
	}
	return (list);
}

void	add_back_list_log_node(t_operation_log_list **list
		, t_operation_log_list *new_node)
{
	if (list == NULL || new_node == NULL)
	{
		return ;
	}
	if (list[0] == NULL)
	{
		list[0] = new_node;
	}
	else
	{
		search_list_last_node(list[0])->next = new_node;
	}
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int						i;
	t_bidrect_circle_list	*head_p;
	t_bidrect_circle_list	*stack_a;
	t_operation_log_list	*log;

	i = 0;
	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	log = NULL;
	head_p = create_stack_a(argc, argv);
	add_back_list_log_node(&log, create_log_node(push(head_p, Push_a)));
	stack_a = head_p->next;
	while (stack_a != head_p)
	{
		printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
		stack_a = stack_a->next;
		i += 1;

	}
	printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
	putstr_log(log);
	log_list_clear(&log);
	stack_clear(&head_p);
	system("leaks -q push_swap");
	return (0);
}
// printf(GREEN"[OK]"END); printf(" : is_digits();\n");
*/
