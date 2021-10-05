#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

// LinkedList's Node
typedef struct ListNodeType
{
	int coef; // 계수
	int degree; //차수
	struct ListNodeType* pLink;//next node
} ListNode;

// LinkedList
typedef struct LinkedListType
{
	int currentElementCount;	// 항
	ListNode *headerNode;		// Header Node
} LinkedList;

// create LinkedList
LinkedList* createLinkedList();

// add element to LinkedList
int addLLElement(LinkedList* pList, int coef, int degree);

// remove element from LinkedList
//int removeLLElement(LinkedList* pList, int degree);

// analyze the polynomial
//int analyze_expression();

// calculate the polynomial
int cal_polynomial(LinkedList *pList, int x);

int main(){
	LinkedList *List = NULL;
	int answer = 0;

	List = createLinkedList();
	if (List){
		addLLElement(List, 6, 6);
		addLLElement(List, 4, 5);
		addLLElement(List, 2, 2);
	}
	answer =cal_polynomial(List ,1);
	printf ("answer is %d\n", answer);
}

LinkedList* createLinkedList(){
	LinkedList* ret = NULL;
	ret = (LinkedList *)malloc(sizeof(LinkedList));

	if (ret != NULL){
    ret->currentElementCount = 0;
    ret->headerNode = NULL;
  }

	return ret;
}

int addLLElement(LinkedList* pList, int coef, int degree){
	int i = -1;
	ListNode* preNode;
	ListNode* newNode;

	if (pList != NULL){
    //full List case
    if (pList->currentElementCount == 0)
      pList->headerNode = (ListNode *)malloc(sizeof(ListNode));
    
    //set preNode pList's headerNode and move to the latest Node
    preNode = pList->headerNode;
    while(++i <= pList->currentElementCount)
      preNode = preNode->pLink;
    
    // set newNode
    newNode = (ListNode *)malloc(sizeof(ListNode));
    newNode->coef = coef;
    newNode->degree = degree;
    newNode->pLink = NULL;

    //add newnode to List
    newNode->pLink = preNode->pLink;
    preNode->pLink = newNode;
    pList->currentElementCount++;
    return true;
  }
  return false;
}

int cal_polynomial(LinkedList *pList, int x){
  int i = -1;
  ListNode* preNode;
  int ret = 0;

  if (pList != NULL){
    preNode = pList->headerNode;
    while (++i < pList->currentElementCount){
      preNode = preNode->pLink;
      ret += preNode->coef * (int)pow(x, (double)preNode->degree);
    }
  }
  return ret;
}
