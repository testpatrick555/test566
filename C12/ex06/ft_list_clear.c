/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 00:09:12 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 02:25:59 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*to_free;

	while (begin_list != 0)
	{
		to_free = begin_list;
		begin_list = begin_list->next;
		free_fct(to_free->data);
		free(to_free);
	}
}
