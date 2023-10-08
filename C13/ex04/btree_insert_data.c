/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:24:53 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 20:58:03 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree	*index;
	t_btree	*prev;
	int		diff;

	if (root != 0)
	{
		index = *root;
		while (index != 0)
		{
			if (cmpf(item, index->item) < 0)
				index = index->left;
			else
				index = index->right;
		}
		index = btree_create_node(item);
	}
}


// t_btree *btree_create_node(void *item)
// {
// 	t_btree	*new_node;

// 	new_node = (t_btree *)malloc(1 * sizeof(t_btree));
// 	new_node->left = 0;
// 	new_node->right = 0;
// 	new_node->item = item;
// 	return (new_node);
// }


// int	main()
// {
	
// 	return (0);
// }