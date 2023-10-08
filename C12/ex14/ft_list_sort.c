/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 02:19:55 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 10:14:44 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list != 0)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

void	ft_list_swap_data(t_list *elem1, t_list *elem2)
{
	void *tmp;

	tmp = elem1->data;
	elem1->data = elem2->data;
	elem2->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*index;
	int	size;
	int	i;

	if (begin_list != 0)
	{
		size = ft_list_size(*begin_list);
		while (size-- > 1)
		{
			i = 0;
			index = *begin_list;
			while (i++ < size)
			{
				if (cmp(index->data, index->next->data) < 0)
					ft_list_swap(index, index->next);
				index = index->next;
			}
		}
	}
}