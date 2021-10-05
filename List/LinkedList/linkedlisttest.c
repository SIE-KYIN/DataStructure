#include "linkedlist.h"

int main(int argc, char* argv[]) {
	int i = 0;
	int arrayCount = 0;
	LinkedList * pList = NULL;
	ListNode * pNode = NULL;
	ListNode node;
	pList = createLinkedList();
	if (pList != NULL) {
		node.data = 1;
		addLLElement(pList, 0, node);
		printf ("0 : %d\n", pList->headerNode.data);
	
		node.data = 3;
		addLLElement(pList, 1, node);
		printf ("1 : %d\n", pList->headerNode.pLink->data);
	
		node.data = 5;
		addLLElement(pList, 2, node);
		printf ("2 : %d\n", pList->headerNode.pLink->pLink->data);
		
		removeLLElement(pList, 0);
		printf ("1 : %d\n", pList->headerNode.pLink->data);
		
		clearLinkedList(pList);
		printf ("1 : %d\n", pList->headerNode.pLink->data);

		deleteLinkedList(pList);
		printf ("1 : %d\n", pList->headerNode.pLink->data);
	}
	return 0;
}
