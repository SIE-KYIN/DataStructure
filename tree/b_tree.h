/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_tree.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:05:58 by mchun             #+#    #+#             */
/*   Updated: 2021/10/25 18:56:37 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BIN_TREE_
#define _BIN_TREE_

typedef struct BinTreeNodeType
{
	char data;
	int visited;
	struct BinTreeNodeType* pLeftChild;
	struct BinTreeNodeType* pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
} BinTree;

BinTree* makeBinTree(BinTreeNode rootNode);			// 무슨 함수일까...?
BinTreeNode* getRootNodeBT(BinTree* pBinTree);		//
BinTreeNode*	insertInRoot(BinTreeNode* root, BinTreeNode element);
BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);		// 경우의 수
BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element);		// 경우의 수
BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode);
BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode);
void	deleteBinTree(BinTree* pBinTree);
void	deleteBinTreeNode(BinTreeNode* pNode);		// 경우의 수..

void	traverseDLR(BinTree *pBinTree);
void	traverseLDR(BinTree *pBinTree);
void	traverseLRD(BinTree *pBinTree);

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0

#endif
