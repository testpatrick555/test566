/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:24:53 by achappui          #+#    #+#             */
/*   Updated: 2023/10/08 14:28:33 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

typedef struct s_queue
{
	struct s_queue	*next;
	t_btree			*node;
}	t_queue;

typedef struct s_norminette
{
	int		append_nb_act;
	int		append_nb_count;
	int		is_first_elem;
	int		current_level;
}	t_norminette;

t_btree	*queue_pop(t_queue **front, t_queue **back) //return l'element pop?
{
	t_queue	*to_free;
	t_btree	*node;

	if (front != NULL && back != NULL)
	{
		to_free = *front;
		node = (*front)->node;
		*front = (*front)->next;
			if (*front == NULL)
				*back = NULL;
		free(to_free);
		return (node);
	}
	return (NULL);
}

int	queue_append(t_queue **front, t_queue **back, t_btree *node) //return si l'objet a ete append ou pas
{
	t_queue	*new_elem;

	if (front != NULL && back != NULL)
	{
		if (node == NULL)
			return (0);
		new_elem = (t_queue *)malloc(1 * sizeof(t_queue)); //j'ai pas checker le malloc
		new_elem->next = NULL;
		new_elem->node = node;
		if (*front != NULL && *back != NULL)
		{
			(*back)->next = new_elem;
			*back = new_elem;
		}
		else
		{
			*front = new_elem;
			*back = new_elem;
		}
		return (1);
	}
	return (0);
}


void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_queue			**front;
	t_queue			**back;
	t_btree			*node;
	t_norminette	s;

	*front = root;
	*back = root;
	s.append_nb_count = 1;
	s.current_level = 0;
	while (*front != NULL)
	{
		s.append_nb_act = s.append_nb_count;
		s.append_nb_count = 0;
		s.is_first_elem = 1;
		while (s.append_nb_act-- > 0)
		{
			node = queue_pop(front, back);
			applyf(node->item, s.current_level, s.is_first_elem);
			if (s.is_first_elem == 1)
				s.is_first_elem = 0;
			s.append_nb_count += queue_append(front, back, node->left);
			s.append_nb_count += queue_append(front, back, node->right);
		}
		s.current_level++;
	}
}
