#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
#define TRUE		1
#define FALSE		0

typedef struct DoublyListNodeType
{
	int data;
	struct DoublyListNodeType* pLLink;
	struct DoublyListNodeType* pRLink;
} DoublyListNode;

typedef struct DoublyListType
{
	int	currentElementCount;
	DoublyListNode	headerNode;
} DoublyList;

DoublyList* createDoublyList();
void deleteDoublyList(DoublyList* pList);
int addDLElement(DoublyList* pList, int position, DoublyListNode element);
int removeDLElement(DoublyList* pList, int position);
void clearDoublyList(DoublyList* pList);
int getDoublyListLength(DoublyList* pList);
DoublyListNode* getDLElement(DoublyList* pList, int position);
void displayDoublyList(DoublyList* pList);

DoublyList* createDoublyList(void){
  DoublyList* D;
  D = (DoublyList*)malloc(sizeof(DoublyList));
  if(D != NULL) //메모리 할당 점검
    memset(D,0, sizeof(DoublyList)); //구조체 초기화 
  else
    return NULL;
  return D;
}

int addDLElement(DoublyList* pList, int position, DoublyListNode element){
    int i = -1;
    DoublyListNode* preNode = NULL;
    DoublyListNode* newNode = NULL;
    DoublyListNode* nextNode = NULL;

    if (pList != NULL){
        if (0<= position && position <= pList->currentElementCount){
            newNode = (DoublyListNode *)malloc(sizeof(DoublyListNode));
            if (newNode != NULL){
                //set each node
                preNode = getDLElement(pList, position);
                *newNode = element;
                if (preNode->pRLink)
                    nextNode = preNode->pRLink;
                // add element
                preNode->pRLink = newNode;
                newNode->pLLink = preNode;
                if (nextNode){
                    newNode->pRLink = nextNode;
                    nextNode->pLLink = newNode;
                }
                // set List info

                pList->currentElementCount++;
                return TRUE;
            }
        }
    }
    return FALSE;
}


DoublyListNode* getDLElement(DoublyList* pList, int position){
  int i = -1;
  DoublyListNode* Node;
  if(pList){
    Node = &(pList->headerNode);
    while(++i < position)
      Node = Node->pRLink; //해당 노드 위치로 이동
    return Node;
  }
  else 
    return NULL;
}

void reverse(DoublyList** head_ref)
{
     DoublyListNode *temp = NULL; 
     DoublyListNode *current = (*head_ref)->headerNode.pRLink;
    
     while (current !=  NULL)
     {
       temp = current->pLLink;
       current->pLLink = current->pRLink;
       current->pRLink = temp;             
       current = current->pLLink;
     }     
      
     if(temp != NULL )
        (*head_ref)->headerNode.pRLink = temp->pLLink;
}   

int removeDLElement(DoublyList* pList, int position){
  DoublyListNode* preNode;
  DoublyListNode* DeleteNode;
  if(pList){
    if(0<=position && position<=pList->currentElementCount)
    {
      preNode = getDLElement(pList, position);
      DeleteNode = preNode->pRLink;
      preNode->pRLink=DeleteNode->pRLink;
      if (DeleteNode->pRLink)
        DeleteNode->pRLink->pLLink= preNode;
      free(DeleteNode);
      pList->currentElementCount--;
      return true;
    }
  }
  return false;
}//삭제

void clearDoublyList(DoublyList* pList){
  if (pList){
    while(pList->currentElementCount > 0){
      removeDLElement(pList, 0);
    }
  }
}// 노드제거

void deleteDoublyList(DoublyList* pList){
  int i = -1;
  DoublyListNode* Node;
  if (pList){
    clearDoublyList(pList);
    free(pList);
  }
}//리스트 삭제

int getDoublyListLength(DoublyList* pList){
  if (pList)
    return(pList->currentElementCount);
  else
    return false;
}//현재 리스트 길이 가져오기

void displayDoublyList(DoublyList* pList){
  int i = 0;
  if (pList != NULL) {
    printf("현재 원소 개수 : %d\n", pList->currentElementCount);
    for (i = 0; i < pList->currentElementCount; i++)
      printf("[%d], %d\n", i, getDLElement(pList, i + 1)->data);
    }
  else {
    printf("원소가 없습니다.\n");
  }
}


int main(int argc, char* argv[]) {

	int i = 0;

	int arrayCount = 0;

	DoublyList * pList = NULL;

	DoublyListNode * pNode = NULL;

	DoublyListNode node;

	pList = createDoublyList();

	if (pList != NULL) {

		node.data = 1;
		addDLElement(pList, 0, node);

 		node.data = 3;
 		addDLElement(pList, 1, node);

 		node.data = 5;
 		addDLElement(pList, 2, node);

 		node.data = 2;
 		addDLElement(pList, 0, node);

 		displayDoublyList(pList);
        reverse(&pList);
 		displayDoublyList(pList);

 
   clearDoublyList(pList);
   displayDoublyList(pList);

 	deleteDoublyList(pList);
 displayDoublyList(pList);
	}

	return 0;

}
