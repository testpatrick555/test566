/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achappui <achappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:53:54 by achappui          #+#    #+#             */
/*   Updated: 2023/10/07 13:46:43 by achappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree *btree_create_node(void *item)
{
	t_btree	*new_node;

	new_node = (t_btree *)malloc(1 * sizeof(t_btree));
	new_node->left = 0;
	new_node->right = 0;
	new_node->item = item;
	return (new_node);
}
