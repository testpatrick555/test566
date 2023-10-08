/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 00:15:30 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 02:25:57 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	if (begin_list != 0)
	{
		while (count++ < nbr && begin_list->next != 0)
			begin_list = begin_list->next;
		if (count != nbr)
			begin_list = 0;
	}
	return (begin_list);
}
