/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:43:33 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 00:04:09 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*go_last;

	if (begin_list != 0)
	{
		go_last = *begin_list;
		if (go_last != 0)
		{
			while (go_last->next != 0)
				go_last = go_last->next;
			go_last->next = ft_create_elem(data);
		}
		else
			*begin_list = ft_create_elem(data);
	}
}

// #include <stdio.h>
// #include <stdlib.h>

// void display(t_list* n)
// {
//   while(n != NULL)
//   {
//     printf("%d ",*(int *)n->data);
//     n = n->next;
//   }
//   printf("\n");
// }

// int main() 
// {
//   t_list *head;
//   head = (t_list*)malloc(sizeof(t_list));
//   int a =1;
//   int b=3;
//   int c = 37;
//   void *ptr=&a;
//   void *pt = &b;
//   void *p = &c;
//   head = ft_create_elem(ptr);
//   head->next= ft_create_elem(pt);
//   ft_list_push_back(&head, p);
//   display(head);
//   return 0;
// }