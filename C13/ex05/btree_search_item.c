/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:24:53 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 21:57:33 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
					int (*cmpf)(void *, void *))
{
	void	*elem;

	if (root != 0)
	{
		elem = 0;
		if (root->left != 0)
			elem = btree_search_item(root->left, data_ref, cmpf);
		if (elem != 0)
			return (elem);
		if (cmpf(data_ref, root->item) == 0)
			return (root->item);
		if (root->right != 0)
			elem = btree_search_item(root->right, data_ref, cmpf);
		if (elem != 0)
			return (elem);
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