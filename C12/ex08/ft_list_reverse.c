/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 00:23:28 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 02:25:56 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

void ft_list_reverse(t_list **begin_list)
{
	t_list	*previous;
	t_list	*next_one;
	
	if (begin_list != 0)
		if (*begin_list != 0 && (*begin_list)->next != 0)
			while ((*begin_list)->next != 0)
			{
				previous = *begin_list;
				*begin_list = (*begin_list)->next;
				next_one = (*begin_list)->next;
				(*begin_list)->next = previous;
				if (next_one != 0)
					*begin_list = next_one;
			}
}
