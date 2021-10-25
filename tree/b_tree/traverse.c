/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traverse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:16:41 by mchun             #+#    #+#             */
/*   Updated: 2021/08/09 19:44:49 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./b_tree.h"

void	preorder_rec(t_tnode *root)
{
	printf("%data : d\t", root->data);
	preorder_rec(root->left);
	preorder_rec(root->right);
	return ;
}

void	inorder_rec(t_tnode *root)
{
	preorder_rec(root->left);
	printf("%data : d\t", root->data);
	preorder_rec(root->right);
	return ;
}

void	postorder_rec(t_tnode *root)
{
	preorder_rec(root->left);
	preorder_rec(root->right);
	printf("%data : d\t", root->data);
	return ;
}

void	levelorder(t_tnode *root)
{
	Queue *Q;
	t_tnode *curr;
	createQueue(Q);

	Enqueue(Q, root);
	while (!isQueueEmpty(Q))
	{
		curr = Dequeue(Q);
		printf("data : %d\n", curr->data);
		if (curr->left)
			Enqueue(Q, curr->left);
		if (curr->right)
			Enqueue(Q, curr->right);
	}
	DeleteQueue(Q);
}
