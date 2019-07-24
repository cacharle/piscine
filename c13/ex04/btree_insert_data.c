/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 18:43:18 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/23 20:49:48 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

// this is half shit
void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (*root == NULL)
		*root = btree_create_elem(item);
	if ((*cmpf)((*root)->item, item) < 0)
		btree_insert_root(&(*root)->left, item, cmpf);
	else if ((*cmpf)((*root)->item, item) > 0)
		btree_insert_root(&(*root)->right, item, cmpf);
}
