/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:23:09 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 10:18:49 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_reverse_fun(t_list *begin_list)
{
	t_list	*previous;
	t_list	*next_one;
	t_list	**begin_list2;
	
	*begin_list2 = begin_list;
	if (*begin_list2 != 0 && (*begin_list2)->next != 0)
		while ((*begin_list2)->next != 0)
		{
			previous = *begin_list2;
			*begin_list2 = (*begin_list2)->next;
			next_one = (*begin_list2)->next;
			(*begin_list2)->next = previous;
			if (next_one != 0)
				*begin_list2 = next_one;
		}
}