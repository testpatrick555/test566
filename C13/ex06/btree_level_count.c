/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:24:53 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 22:20:44 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	count_l;
	int	count_r;

	if (root != 0)
	{
		count_l = 1;
		count_r = 1;
		if (root->left != 0)
			count_l += btree_level_count(root->left);
		if (root->right != 0)
			count_r += btree_level_count(root->right);
		if (count_l >= count_r)
			return (count_l);
		else
			return (count_r);
	}
	return (0);
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