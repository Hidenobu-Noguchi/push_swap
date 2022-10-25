/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/10/25 19:57:13 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_bidrect_circle_list	*head_p_stack_a;
	t_bidrect_circle_list	*head_p_stack_b;
	t_bidrect_circle_list	*stack_a;
	t_bidrect_circle_list	*stack_b;

	t_list					*head_p_log;
	t_list					*log_node;
	t_list					*log_list;

	if (argc <= 1)
	{
		return (0);
	}
	validation_args(argc, argv);
	head_p_stack_a = create_stack_a(argc, argv);
	head_p_stack_b = create_sentinel();
	stack_a = head_p_stack_a;
	stack_b = head_p_stack_b;

	head_p_log = NULL;
	log_list = NULL;

	log_node = ft_lstnew(push_b(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);
	head_p_log = log_list;

	log_node = ft_lstnew(push_b(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(reverse_rotate_a(stack_a));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(reverse_rotate_b(stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(reverse_rotate_r(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_b(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(reverse_rotate_a(stack_a));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(reverse_rotate_r(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_b(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(reverse_rotate_a(stack_a));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(reverse_rotate_r(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_a(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew(push_a(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew(push_a(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(reverse_rotate_b(stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(reverse_rotate_r(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_a(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(reverse_rotate_b(stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(reverse_rotate_r(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	stack_a = head_p_stack_a->next;
	stack_b = head_p_stack_b->next;
	printf(" stack_a | stack_b\n");
	while (stack_a != head_p_stack_a || stack_b != head_p_stack_b)
	{
		if (stack_a == head_p_stack_a)
		{
			printf("         | [%d]\n", stack_b->num);
		}
		else if (stack_b == head_p_stack_b)
		{
			printf(" [%d]     |\n", stack_a->num);
		}
		else
		{
			printf(" [%d]     | [%d]\n", stack_a->num, stack_b->num);
		}
		if (stack_a != head_p_stack_a)
		{
			stack_a = stack_a->next;
		}
		if (stack_b != head_p_stack_b)
		{
			stack_b = stack_b->next;
		}
	}
	printf("------------------\n");
	printf(" [%d]     | [%d]\n", stack_a->num, stack_b->num);
	
	stack_clear(&head_p_stack_a);
	stack_clear(&head_p_stack_b);
	while (log_list)
	{
		// if (log_list->content)
		//{
			// ft_printf("[%s]\n", (char *)log_list->content);
			ft_putstr_fd((char *)log_list->content, 1);
			ft_putstr_fd("\n", 1);
		//}
		log_list = log_list->next;
	}
	ft_lstclear(&head_p_log, NULL);
	system("leaks -q push_swap");
	return (0);
}
// printf(GREEN"[OK]"END); printf(" : is_digits();\n");
// search_max();
// compress();
// sort();
// execute_push_swap();
/*
	log_node = ft_lstnew(swap_a(stack_a));
	ft_lstadd_back(&log_list, log_node);
	head_p_log = log_list;

	log_node = ft_lstnew(swap_b(stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(swap_s(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_a(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_b(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);
	head_p_log = log_list;
	log_node = ft_lstnew(push_b(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(swap_b(stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(swap_s(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(rotate_a(stack_a));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(rotate_b(stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(rotate_r(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_b(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(rotate_a(stack_a));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(rotate_r(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_b(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(rotate_a(stack_a));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(rotate_r(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_a(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew(push_a(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);
	log_node = ft_lstnew(push_a(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(rotate_b(stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(rotate_r(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_a(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(rotate_b(stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(rotate_r(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

	log_node = ft_lstnew(push_a(stack_a, stack_b));
	ft_lstadd_back(&log_list, log_node);

*/

