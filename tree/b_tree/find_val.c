/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_val.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:17:33 by mchun             #+#    #+#             */
/*   Updated: 2021/08/09 20:29:38 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_tree.h"

t_tnode *find_val(t_tnode *root, int data)
{
	t_tnode *ret_node;

	if (!root)
		return (NULL);
	if (root->data == data)
		return (root);

	ret_node = find_val(root->left, data);
	if (ret_node != NULL)
		return (ret_node);
	ret_node == find_val(root->right, data);
	if (ret_node != NULL)
		return (ret_node);
	return (NULL);
}
