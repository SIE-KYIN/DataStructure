/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_tree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchun <mchun@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:11:21 by mchun             #+#    #+#             */
/*   Updated: 2021/10/25 19:57:42 by mchun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./b_tree.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

//굳이 rootNode가 있는 상태로 Tree를 만들어야 하는가?

static BinTreeNode	*create_BinTreeNode(BinTreeNode *left, BinTreeNode *right, char data)
{
	BinTreeNode *new = malloc(sizeof(BinTreeNode));
	if (!new)
		return (NULL);
	new->data = data;
	new->pLeftChild = left;
	new->pRightChild = right;
	return (new);
}

BinTree*		makeBinTree(BinTreeNode rootNode)
{
	BinTree *newTree = malloc(sizeof(BinTree));
	BinTreeNode *newNode = malloc(sizeof(BinTreeNode));
	newNode->pLeftChild = NULL;
	newNode->pRightChild = NULL;
	newNode->visited = 0;
	newNode->data = rootNode.data;

	newTree->pRootNode = newNode;
	return (newTree);
}

BinTreeNode*	getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree)
		return NULL;
	return (pBinTree->pRootNode);
}


/*
	parentNode가 없을 경우

*/

BinTreeNode*	insertInRoot(BinTreeNode* root, BinTreeNode element)
{
	BinTreeNode *new = create_BinTreeNode(root, NULL, element.data);
	return (new);
}

BinTreeNode*	insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *new = create_BinTreeNode(NULL, NULL, element.data);
	pParentNode->pLeftChild = new;
	return (new);
}

BinTreeNode*	insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	BinTreeNode *new = create_BinTreeNode(NULL, NULL, element.data);
	pParentNode->pRightChild= new;
	return (new);
}

BinTreeNode*	getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return NULL;
	return (pNode->pLeftChild);
}

BinTreeNode*	getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode)
		return NULL;
	return (pNode->pRightChild);

}

static void		_deleteBinTree(BinTreeNode *root)
{

	if (!root)
		return ;
	_deleteBinTree(root->pLeftChild);
	_deleteBinTree(root->pRightChild);
	free(root);
}

void			deleteBinTree(BinTree* pBinTree)
{
	if (!pBinTree)
		return ;
	_deleteBinTree(pBinTree->pRootNode);
	free(pBinTree);
}

void			deleteBinTreeNode(BinTreeNode* pNode)
{
	//delete only leaf node;
	if (pNode->pLeftChild || pNode->pRightChild)
		return ;
	free(pNode);
}

// void			deleteBinTreeNode_ver2(BinTreeNode* pNode)
// {
// 	free(pNode);
// 	pNode = NULL;
// }

//DLR
static void		_traverseDLR(BinTreeNode *root)
{
	if (!root)
		return ;
	printf("%c ", root->data);
	_traverseDLR(root->pLeftChild);
	_traverseDLR(root->pRightChild);
	return ;
}

void	traverseDLR(BinTree *pBinTree)
{
	BinTreeNode *root;

	if (!pBinTree)
		return ;
	root = pBinTree->pRootNode;
	_traverseDLR(root);
}

//LDR
static void		_traverseLDR(BinTreeNode *root)
{
	if (!root)
		return ;
	_traverseLDR(root->pLeftChild);
	printf("%c ", root->data);
	_traverseLDR(root->pRightChild);
	return ;
}

void	traverseLDR(BinTree *pBinTree)
{
	BinTreeNode *root;

	if (!pBinTree)
		return ;
	root = pBinTree->pRootNode;
	_traverseLDR(root);
}

//LRD
static void		_traverseLRD(BinTreeNode *root)
{
	if (!root)
		return ;
	_traverseLRD(root->pLeftChild);
	_traverseLRD(root->pRightChild);
	printf("%c ", root->data);
	return ;
}

void	traverseLRD(BinTree *pBinTree)
{
	BinTreeNode *root;

	if (!pBinTree)
		return ;
	root = pBinTree->pRootNode;
	_traverseLRD(root);
}


//Level order Traversal
// void	traverseLevel(BinTree *pBinTree)
// {
// 	BinTreeNode *root = pBinTree->pRootNode;
// 	BinTreeNode *curr;

// 	if (!root)
// 		return ;
// 	Queue	*Q = createQueue();

// 	enQueue(Q, root);
// 	while (!isQueueEmpty(Q))
// 	{
// 		curr = deQueue(Q);
// 		printf("%d\n", curr->data);
// 		if (curr->pLeftChild)
// 			enQueue(curr->pLeftChild);
// 		if (curr->pRightChild)
// 			enQueue(curr->pRightChild);
// 	}
// }


//DLR with non_recursive way

// 중요 포인트 : 재귀로 생각할 수 있는 부분이 존재하기에 재귀적으로 생각해보는(일반화/귀납적으로 생각할 수 있는 부분이 존재한다.)
// void	traverseLDR_nonrecursive(BinTreeNode *root)
// {
// 	BinTreeNode *curr;
// 	Stack	*S;

// 	curr = root;
// 	do
// 	{
// 		while (curr->pLeftChild)
// 		{
// 			push(curr);
// 			curr = curr->pLeftChild;
// 		}

// 		{
// 			print(curr);
// 		}

// 		if (curr->pRightChild)
// 			curr = curr->pRightChild;
// 		else
// 		{
// 			do
// 			{
// 				curr = pop(S);
// 				curr = curr->pRightChild;
// 			} while (curr->pRightChild);
// 		}
// 	} while (isStackEmtpy(S));
// }

// void	traverseDLR_nonrecursive(BinTreeNode *root)
// {
// 	BinTreeNode *curr;
// 	Stack	*S;

// 	curr = root;
// 	do
// 	{
// 		while (curr->pLeftChild)
// 		{
// 			print(curr);
// 			push(curr);
// 			curr = curr->pLeftChild;
// 		}
// 		print(curr);

// 		if (curr->pRightChild)
// 			curr = curr->pRightChild;
// 		else
// 		{
// 			do
// 			{
// 				curr = pop(S);
// 				curr = curr->pRightChild;
// 			} while (curr->pRightChild);
// 		}
// 	} while (isStackEmtpy(S));
// }





BinTree *createExampleBinTree() {
    BinTree *pReturn = NULL;
    BinTreeNode *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
    BinTreeNode *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL;
    BinTreeNode *pNodeG = NULL, *pNodeH = NULL, *pNodeI = NULL;
    BinTreeNode *pNodeJ = NULL, *pNodeK = NULL, *pNodeL = NULL;
    BinTreeNode *pNodeM = NULL;
    BinTreeNode node = {0,};

    node.data = 'A';
    pReturn = makeBinTree(node);
    if (pReturn != NULL) {
        pNodeA = getRootNodeBT(pReturn);
        node.data = 'B';
        pNodeB = insertLeftChildNodeBT(pNodeA, node);
        node.data = 'C';
        pNodeC = insertRightChildNodeBT(pNodeA, node);
        if (pNodeB != NULL) {
            node.data = 'D';
            pNodeD = insertLeftChildNodeBT(pNodeB, node);
            node.data = 'E';
            pNodeE = insertRightChildNodeBT(pNodeB, node);
        }
        if (pNodeC != NULL) {
            node.data = 'F';
            pNodeF = insertLeftChildNodeBT(pNodeC, node);
            node.data = 'G';
            pNodeG = insertRightChildNodeBT(pNodeC, node);
        }
        if (pNodeD != NULL) {
            node.data = 'H';
            pNodeH = insertLeftChildNodeBT(pNodeD, node);
            node.data = 'I';
            pNodeI = insertRightChildNodeBT(pNodeD, node);
        }
        if (pNodeE != NULL) {
            node.data = 'J';
            pNodeJ = insertLeftChildNodeBT(pNodeE, node);
        }
        if (pNodeF != NULL) {
            node.data = 'K';
            pNodeK = insertRightChildNodeBT(pNodeF, node);
        }
        if (pNodeG != NULL) {
            node.data = 'L';
            pNodeL = insertLeftChildNodeBT(pNodeG, node);
            node.data = 'M';
            pNodeM = insertRightChildNodeBT(pNodeG, node);
        }
    }

    return pReturn;
}


int main() {
    BinTree *pBinTree = NULL;
    pBinTree = createExampleBinTree();
    if (pBinTree != NULL) {
        printf("Preorder Iterative Traversal\n");
        traverseDLR(pBinTree);

        printf("\nInorder Iterative Traversal\n");
        traverseLDR(pBinTree);

        printf("\nPostorder Iterative Traversal\n");
        traverseLRD(pBinTree);

        deleteBinTree(pBinTree);
    }

    return 0;
}
