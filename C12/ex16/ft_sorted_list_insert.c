/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:22:59 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 12:20:22 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// #include <stdio.h>
// #include <stdlib.h>

// int    ft_strcmp(void *data1, void *data2)
// {
//     return (*(int *)data1 - *(int *)data2);
// }

// t_list *ft_create_elem(void *data)
// {
//     t_list* new_node;
    
//     new_node = (t_list*)malloc(sizeof(t_list));
//     if(new_node)
//     {
//         new_node->data = data;
//         new_node->next = NULL;
//     }
//     return (new_node);
// }

void	ft_sorted_list_insert2(t_list **begin_list, void *data, \
								int (*cmp)(), t_list *new_elem)
{
	t_list	*prev;
	t_list	*index;

	prev = 0;
	index = *begin_list;
	while (index->next != 0 && cmp(data, index->data) >= 0)
	{
		prev = index;
		index = index->next;
	}
	if (cmp(data, index->data) < 0)
	{
		new_elem->next = index;
		if (prev == 0)
			*begin_list = new_elem;
		else
			prev->next = new_elem;
	}
	else
	{
		new_elem->next = index->next;
		index->next = new_elem;
	}
}

void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new_elem;

	if (begin_list != 0)
	{
		new_elem = ft_create_elem(data);
		if (*begin_list == 0)
			*begin_list = new_elem;
		else
			ft_sorted_list_insert2(begin_list, data, cmp, new_elem);
	}
}

// void display(t_list *head)
// {
//     while(head != NULL)
//     {
//         printf("%d ",*(int *)head->data);
//         head = head->next;
//     }
// }

// int main()
// {
//     int a = 10, b = 20, x= 30, o = 31;
//     void*    d =&a;
//     void*    e =&b;
//     void*    i = &x;
//     void*    q = &o;
//     t_list* head=(t_list*)malloc(sizeof(t_list));
//     head = ft_create_elem(d);
//     head->next = ft_create_elem(e);
//     head->next->next = ft_create_elem(i);
//     display(head);
//     printf("\n");
//     ft_sorted_list_insert(&head, q, ft_strcmp);
//     display(head);
// 	printf("\n");
//     return (0);
// }