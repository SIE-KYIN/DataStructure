/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_maxval.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 19:47:00 by mchun             #+#    #+#             */
/*   Updated: 2021/08/09 20:15:35 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_tree.h"

int		find_maxval(t_tnode *root)
{
	int		max_val;
	int		left_val;
	int		right_val;

	if (!root)
		return (INT_MIN);
	max_val = root->data;
	left_val = find_maxval(root->left);
	if (left_val > root->data)
		max_val = left_val;
	right_val = find_maxval(root->right);
	if (right_val > max_val)
		max_val = right_val;
	return (max_val);
}


/* with no recursion,  virtual stack */
int		find_maxval_nonrec(t_tnode *root)
{
	int		max;
	Queue *Q;
	t_tnode *curr;
	createQueue(Q);

	Enqueue(Q, root);
	max = root->data;
	curr = root;
	while (isQueueEmpty(Q))
	{
		curr = Dequeue(Q);
		if (curr->data > max)
			max = curr->data;
		if (curr->left)
			Enqueue(Q, curr->left);
		if (curr->right)
			Enqueue(Q, curr->right);
	}
	DeleteQueue(Q);
}
