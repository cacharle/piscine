/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:49:54 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/24 14:15:46 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
							int (*cmpf)(void *, void *))
{
	void	*tmp;

	if (root == NULL)
		return (NULL);
	tmp = btree_search_item(root->left, data_ref, cmpf);
	if (tmp != NULL)
		return (tmp);
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	tmp = btree_search_item(root->right, data_ref, cmpf);
	if (tmp != NULL)
		return (tmp);
	return (NULL);
}
