/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:51:34 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/24 12:28:45 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	left_level;
	int	right_level;

	if (root == NULL)
		return (0);
	left_level = 0;
	right_level = 0;
	if (root->left != NULL)
		left_level = btree_level_count(root->left);
	if (root->right != NULL)
		right_level = btree_level_count(root->right);
	if (left_level >= right_level)
		return (1 + left_level);
	else
		return (1 + right_level);
}
