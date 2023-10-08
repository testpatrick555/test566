/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:22:53 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 12:35:34 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

// #include <stdlib.h>
// #include <stdio.h>

// int    ft_strcmp(void *data1, void *data2)
// {
//     return (*(int *)data1 - *(int *)data2);
// }


void	ft_sorted_list_insert_b2(t_list **begin_list, t_list *begin_list2, \
								int (*cmp)())
{
	t_list	*prev;
	t_list	*index;

	prev = 0;
	index = *begin_list;
	while (index->next != 0 && cmp(begin_list2->data, index->data) >= 0)
	{
		prev = index;
		index = index->next;
	}
	if (cmp(begin_list2->data, index->data) < 0)
	{
		begin_list2->next = index;
		if (prev == 0)
			*begin_list = begin_list2;
		else
			prev->next = begin_list2;
	}
	else
	{
		begin_list2->next = index->next;
		index->next = begin_list2;
	}
}

void ft_sorted_list_insert_b(t_list **begin_list, t_list *begin_list2, \
							int (*cmp)())
{
	if (begin_list != 0)
	{
		if (*begin_list == 0)
		{
			*begin_list = begin_list2;
			begin_list2->next = 0;
		}
		else
			ft_sorted_list_insert_b2(begin_list, begin_list2, cmp);
	}
}

void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, int (*cmp)())
{
	t_list	*next;
	
	if (begin_list1 != 0)
	{
		while (begin_list2 != 0)
		{
			next = begin_list2->next;
			ft_sorted_list_insert_b(begin_list1, begin_list2, cmp);
			begin_list2 = next;
		}
	}
}

// t_list *ft_create_elem(void *data)
// {
// 	t_list* new_node;
	
// 	new_node = (t_list*)malloc(sizeof(t_list));
// 	if(new_node)
// 	{
// 		new_node->data = data;
// 		new_node->next = NULL;
// 	}
// 	return (new_node);
// }

// void display(t_list *head)
// {
// 	while(head != NULL)
// 	{
// 		printf("%d ",*(int *)head->data);
// 		head = head->next;
// 	}
// }

// int main()
// {
// 	int a = 10, b = 20, c = 30, x= 40, z = 23, l = 13, o = 0;
// 	void*	d =&a;
// 	void*	e =&b;
// 	void*	f = &c;
// 	void*	i = &x;
// 	void*   y = &z;
// 	void*	w = &l;
// 	void*	q = &o;
// 	t_list* head=(t_list*)malloc(sizeof(t_list));
// 	t_list* head2 = (t_list*)malloc(sizeof(t_list));

// 	head = ft_create_elem(d);
// 	head->next = ft_create_elem(e);
// 	head->next->next = ft_create_elem(f);
// 	head->next->next->next = ft_create_elem(i);
// 	display(head);
// 	printf("\n");

// 	head2 = ft_create_elem(y);
// 	head2->next= ft_create_elem(w);
// 	head2->next->next = ft_create_elem(q);
// 	display(head2);
// 	printf("\n");

// 	ft_sorted_list_merge(&head, head2, ft_strcmp);
	
// 	display(head);
// 	printf("\n");
// 	return (0);
// }