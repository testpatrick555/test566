/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:13:31 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 02:25:44 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*index;
	if (begin_list1 != 0)
	{
		if (*begin_list1 != 0)
		{
			index = *begin_list1;
			while (index->next != 0)
				index = index->next;
			index = begin_list2;
		}
		else
			*begin_list1 = begin_list2;
	}
}