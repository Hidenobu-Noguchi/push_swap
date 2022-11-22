/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:37:59 by hnoguchi          #+#    #+#             */
/*   Updated: 2022/11/22 11:36:27 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_dcl_list *head_p)
{
	int						len;
	t_dcl_list	*node;

	len = 0;
	node = head_p->next;
	while (node != head_p)
	{
		len += 1;
		node = node->next;
	}
	return (len);
}
