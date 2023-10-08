/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:13:28 by achappui          #+#    #+#             */
/*   Updated: 2023/10/06 23:34:43 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new_elem;

	if (begin_list != 0)
	{
		new_elem = ft_create_elem(data);
		if (*begin_list != 0)
			new_elem->next = *begin_list;
		*begin_list = new_elem;
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
//   t_list* head;

//   head = (t_list *)malloc(sizeof(t_list));
//   head = NULL;
//   int a = 13;
//   int b = 3;
//   int c = 7;
//   void *ptr = &a;
//   void *p = &b;
//   void *pt = &c;
//   ft_list_push_front(&head, ptr);
//   ft_list_push_front(&head, p);
//   ft_list_push_front(&head, pt);
//   display(head);
//   free(head);
//   return 0;
// } 