#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 

typedef struct ListNodeType
{
	int data;
	struct ListNodeType* pLink;
} ListNode;

typedef struct LinkedListType
{
	int currentElementCount;	// «ˆ¿Á ¿˙¿Âµ» ø¯º“¿« ∞≥ºˆ
	ListNode headerNode;		// «Ï¥ı ≥ÎµÂ(Header Node)
} LinkedList;

LinkedList* createLinkedList();
int addLLElement(LinkedList* pList, int position, ListNode element);
int removeLLElement(LinkedList* pList, int position);
ListNode* getLLElement(LinkedList* pList, int position);

void clearLinkedList(LinkedList* pList);
int getLinkedListLength(LinkedList* pList);
void deleteLinkedList(LinkedList* pList);

LinkedList* createLinkedList(void){
  LinkedList* L;
  L = (LinkedList*)malloc(sizeof(LinkedList));
  if(L != NULL)
    memset(L,0, sizeof(LinkedList));
  else
    return NULL;
  return L;
}


int addLLElement(LinkedList* pList, int position, ListNode element){
  int i = -1;
  ListNode* preNode;
  ListNode* newNode;
  if (pList){
    if (0<= position && position <= pList->currentElementCount){
  newNode = (ListNode*)malloc(sizeof(ListNode));
  if(newNode){
  preNode = getLLElement(pList, position-1);
  *newNode = element;
  newNode->pLink = preNode->pLink;
  preNode->pLink = newNode; 
  pList->currentElementCount++;
  return true;
    }
  }

  }
    return false;
}

int removeLLElement(LinkedList* pList, int position){
  ListNode* preNode;
  ListNode* tmp;
  if(pList){
    if(0<=position && position <=pList->currentElementCount){
  preNode = getLLElement(pList, position - 1);
  tmp = preNode->pLink;
  preNode->pLink = tmp->pLink;
  free(tmp);
  pList->currentElementCount--;
  return true;
    }
  }
  return false;
}

ListNode* getLLElement(LinkedList* pList, int position){
    int i = -1;
  ListNode* Node;
    if(pList){
  Node = &(pList->headerNode);

  while(++i <= position)
   Node = Node->pLink;
  return Node;
    }
    else 
    return NULL;
}


void clearLinkedList(LinkedList* pList){
    int i = -1;
  ListNode* Node;
if (pList){
  Node = (ListNode*)malloc(sizeof(ListNode));
  
  Node = &(pList->headerNode);

  while(++i < pList->currentElementCount){
   Node = Node->pLink;
   Node->data = 0;
}
}
}

int getLinkedListLength(LinkedList* pList){
  if (pList)
  return(pList->currentElementCount);
  else
  return false;
}

void deleteLinkedList(LinkedList* pList){
    int i = -1;
  ListNode* Node;
  if (pList){
  Node = &(pList->headerNode);

  while(++i < pList->currentElementCount){
   Node = Node->pLink;
   free(Node);
}
Node = NULL;
  free(pList);
  }
}

void displayLinkedList(LinkedList* pList) {

    int i = 0;

    if (pList != NULL) {

        printf("현재 원소 개수 : %d\n", pList->currentElementCount);

        for (i = 0; i < pList->currentElementCount; i++) {

            printf("[%d], %d\n", i, getLLElement(pList, i)->data);

        }

    }

    else {

        printf("원소가 없습니다.\n");

    }

}


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

		node.data = 3;

		addLLElement(pList, 1, node);

		node.data = 5;

		addLLElement(pList, 2, node);

		displayLinkedList(pList);

		removeLLElement(pList, 0);

		displayLinkedList(pList);
clearLinkedList(pList);
displayLinkedList(pList);

	deleteLinkedList(pList);
displayLinkedList(pList);
	}

	return 0;

}
