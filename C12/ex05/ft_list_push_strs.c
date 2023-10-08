/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 23:59:03 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 02:26:00 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_list_push_strs(int size, char **strs)
{
	t_list	*new_elem;
	t_list	*begin_list;

	if (size > 0)
	{
		new_elem = ft_create_elem(strs[size]);
		begin_list = new_elem;
		while (--size > 0)
		{
			new_elem->next = ft_create_elem(strs[size]);
			new_elem = new_elem->next;
		}
	}
	return (begin_list);
}


// #include <stdio.h>
// #include <stdlib.h>
// int        main(void)
// {
//     t_list    *begin;
//     char    **strs;

//     begin = (t_list *)malloc(sizeof(t_list));
//     strs = malloc(sizeof(char*) * 3);
//     strs[0] = malloc(sizeof(char*) * 10);
//     strs[1] = malloc(sizeof(char*) * 6);
//     strs[0] = "Benguerir";
//     strs[1] = "1337 ";
//     begin = ft_list_push_strs(2, strs);
//     while (begin)
//     {
//         printf("%s", (char *)begin->data);
//         begin = begin->next;
//     }
//     return (0);
// }