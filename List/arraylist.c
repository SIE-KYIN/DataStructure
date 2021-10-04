#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ArrayListNodeType
{
	int data;
} ArrayListNode;

typedef struct ArrayListType
{
	int maxElementCount;		// �ִ� ���� ����
	int currentElementCount;	// ���� ������ ����
	ArrayListNode *pElement;	// ���� ������ ���� 1���� �迭
} ArrayList;

ArrayList* createArrayList(int maxElementCount);
void deleteArrayList(ArrayList* pList);
int isArrayListFull(ArrayList* pList);
int addALElement(ArrayList* pList, int position, ArrayListNode element);
int removeALElement(ArrayList* pList, int position);
ArrayListNode* getALElement(ArrayList* pList, int position);
void displayArrayList(ArrayList* pList);
void clearArrayList(ArrayList* pList);
int getArrayListLength(ArrayList* pList);

//kyujlee

ArrayList* createArrayList(int maxElementCount){
  ArrayList* ret;
  int i = -1;
  ret = (ArrayList*)malloc(sizeof(ArrayList));

  if (ret == NULL || maxElementCount < 0)
    return NULL;
  
  ret->maxElementCount = maxElementCount;
  ret->currentElementCount = 0;
  ret->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode)*maxElementCount);

  if (ret->pElement == NULL)
    return NULL;
  
  while (++i < maxElementCount)
    (ret->pElement + i)->data = 0;
  
  return ret;
   
}

//kyujlee
void deleteArrayList(ArrayList* pList){
  free(pList->pElement);
  free(pList);
}

int isArrayListFull(ArrayList* pList){
  if (pList->maxElementCount == pList->currentElementCount)
    return true;
  else
    return false;
}


//kypark??
int addALElement(ArrayList* pList, int position, ArrayListNode element){
   if(pList !=NULL){
     if (isArrayListFull(pList) == 0){//리스트 꽉안찼으면 
       if((position >= 0) && (position <= getArrayListLength(pList)) ){ //0이상 maxElementCount이하
        for (int i = getArrayListLength(pList); i >= position; i--)
        {
         (pList->pElement + i +1)->data = (pList->pElement + i)->data;
        }
        pList->pElement[position] = element;
        pList->currentElementCount++;       
       }
       return true;
     }
     else //리스트 꽉찼으면
      printf("리스트 꽉참");
   }
  return false;
}


int removeALElement(ArrayList* pList, int position){
  if (pList != NULL && position >= 0 && (position < getArrayListLength(pList))){
    for (int i = position + 1; i < getArrayListLength(pList); i++)
      (pList->pElement + i - 1)->data = (pList->pElement + i)->data;
    pList->currentElementCount--;       
    return true;
  }
  else 
    return false;
}

//kyujlee
void displayArrayList(ArrayList* pList){
  int idx = -1;
  
  if (pList)
    while (++idx < pList->currentElementCount)
      printf ("%dst data is %d\n",idx +1 , ((pList->pElement + idx)->data));
}

ArrayListNode* getALElement(ArrayList* pList, int position){
  
  if (pList != NULL || position < pList->currentElementCount)
    return (&pList->pElement[position - 1]);
  else
    return NULL;
}

//kypark
int getArrayListLength(ArrayList* pList){
  int ret;
  if (pList != NULL){
    ret = pList-> currentElementCount;
  }
  return ret;
}

//kypark
void clearArrayList(ArrayList* pList){
  for(int i=0; i < pList->currentElementCount; i++)
  {
    (pList->pElement + i)->data = 0;
  }
}

int main()
{
  ArrayList* tmp;
  ArrayListNode tmpnode;

  tmp = createArrayList(10);
  tmp->pElement->data = 0;
  (tmp->pElement+1)->data = 1;
  (tmp->pElement+2)->data = 2;
  (tmp->pElement+3)->data = 3;
  (tmp->pElement+4)->data = 4;
  (tmp->pElement+5)->data = 5;
  (tmp->pElement+6)->data =6;
  displayArrayList(tmp);
 
  printf ("\n\n\n");


  clearArrayList(tmp);
    displayArrayList(tmp);

}
