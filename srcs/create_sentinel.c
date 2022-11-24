/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sentinel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/24 19:10:33 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_dcl_list	*create_sentinel(void)
{
	t_dcl_list	*sentinel;

	sentinel = (t_dcl_list *)malloc(sizeof(t_dcl_list));
	if (!sentinel)
	{
		return (NULL);
	}
	sentinel->num = -1;
	sentinel->index = -1;
	sentinel->prev = sentinel;
	sentinel->next = sentinel;
	return (sentinel);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int						i;
	t_bidrect_circle_list	*head_p;
	t_bidrect_circle_list	*stack_a;

	i = 0;
	head_p = create_stack_a(argc, argv);
	stack_a = head_p->next;
	while (stack_a != head_p)
	{
		printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
		stack_a = stack_a->next;
		i += 1;

	}
	printf("[%2d] stack_a->num = [%d]\n", i, stack_a->num);
	stack_clear(&head_p);
	system("leaks -q push_swap");
	return (0);
}
*/
