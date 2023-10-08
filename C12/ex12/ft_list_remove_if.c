/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 00:48:18 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 12:36:09 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>
// #include <stdio.h>

// void ft_free(void *data)
// {
//     printf("%d\n", *(int *) data);
//     data = NULL;
// }

// int    ft_strcmp(void *data1, void *data2)
// {
//     return (*(int *)data1 - *(int *)data2);
// }


void	update_begin_list(t_list **begin_list, void *data_ref, \
						int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*index;
	
	if (begin_list != 0 && *begin_list != 0)
	{
		index = *begin_list;
		while (cmp((*begin_list)->data, data_ref) == 0)
		{
			*begin_list = (*begin_list)->next;
			free_fct(index->data);
			free(index);
			index = *begin_list;
		}
	}
}

void ft_list_remove_if(t_list **begin_list, void *data_ref, \
						int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*index;
	t_list	*prev;

	update_begin_list(begin_list, data_ref, cmp, free_fct);
	if (begin_list != 0 && *begin_list != 0)
	{
		prev = *begin_list;
		index = (*begin_list)->next;
		while(index != 0)
		{
			if (cmp(index->data, data_ref) == 0)
			{
				index = index->next;
				free_fct(prev->next->data);
				free(prev->next);
				prev->next = index;
			}
			else
			{
				prev  = index;
				index = index->next;
			}
		}
	}
}

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

// void display(t_list *head)
// {
// 	printf("Data des elements de la liste: ");
//     while(head != NULL)
//     {
//         printf("%d ",*(int *)head->data);
//         head = head->next;
//     }
// 	printf("\n");
// }

// int main()
// {
//     int a = 40, b = 20, x= 40, o = 40;
//     void*    d =&a;
//     void*    e =&b;
//     void*    i = &x;
//     void*    q = &o; //o est la data de reference
//     t_list* head=(t_list*)malloc(sizeof(t_list));
//     head = ft_create_elem(d);
//     head->next = ft_create_elem(e);
//     head->next->next = ft_create_elem(i);
//     display(head);
//     printf("Ellements supprimes: \n");
//     ft_list_remove_if(&head, q, ft_strcmp, ft_free);
//     display(head);
//     return (0);
// }