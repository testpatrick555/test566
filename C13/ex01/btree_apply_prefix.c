/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:24:53 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 13:46:42 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root != 0)
	{
		applyf(root->item);
		if (root->left != 0)
			btree_apply_prefix(root->left, applyf);
		if (root->right != 0)
			btree_apply_prefix(root->right, applyf);
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