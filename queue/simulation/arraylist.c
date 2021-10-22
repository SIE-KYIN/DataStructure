#include "arraylist.h"

// create arrayList
ArrayList* createArrayList(int maxElementCount){
  ArrayList* ret;
  int i = -1;
  ret = (ArrayList*)malloc(sizeof(ArrayList));// make ArrayList

  if (ret == NULL || maxElementCount < 0)
    return NULL;
  
  ret->maxElementCount = maxElementCount;
  ret->currentElementCount = 0;
  ret->pElement = (ArrayListNode *)calloc(maxElementCount, sizeof(ArrayListNode));// make node

  if (ret->pElement == NULL)
    return NULL;
  
  return ret;
}

// delete arraylist
void deleteArrayList(ArrayList* pList){
  free(pList->pElement);
  free(pList);
}

// check the array whether it is full
int isArrayListFull(ArrayList* pList){
  if (pList->maxElementCount == pList->currentElementCount)
    return TRUE;
  else
    return FALSE;
}

// add element to arraylist
int addALElement(ArrayList* pList, int position, ArrayListNode element){
   if(pList !=NULL){
     if (isArrayListFull(pList) == 0){//List is not full then work
       if((position >= 0) && (position <= getArrayListLength(pList))){
		//from back to position move data then add element to empty space
        for (int i = getArrayListLength(pList); i >= position; i--)
        {
         (pList->pElement + i +1)->arrivalTime = (pList->pElement + i)->arrivalTime;
         (pList->pElement + i +1)->endTime = (pList->pElement + i)->endTime;
         (pList->pElement + i +1)->serviceTime = (pList->pElement + i)->serviceTime;
         (pList->pElement + i +1)->startTime = (pList->pElement + i)->startTime;
         (pList->pElement + i +1)->status = (pList->pElement + i)->status;
         //(pList->pElement + i +1) = (pList->pElement + i);
        }
        pList->pElement[position] = element;
        pList->currentElementCount++;       
       }
       return TRUE;
     }
     else
      printf("List is FULL\n");
   }
  return FALSE;
}

// remove element from arraylist
int removeALElement(ArrayList* pList, int position){
  if (pList != NULL && position >= 0 && (position < getArrayListLength(pList))){
    for (int i = position + 1; i < getArrayListLength(pList); i++){
      (pList->pElement + i -1)->arrivalTime = (pList->pElement + i)->arrivalTime;
      (pList->pElement + i -1)->endTime = (pList->pElement + i)->endTime;
      (pList->pElement + i -1)->serviceTime = (pList->pElement + i)->serviceTime;
      (pList->pElement + i -1)->startTime = (pList->pElement + i)->startTime;
      (pList->pElement + i -1)->status = (pList->pElement + i)->status;
    }
    pList->currentElementCount--;
    return TRUE;
  }
  else 
    return FALSE;
}

// show arraylist's data
/*
void displayArrayList(ArrayList* pList){
  int idx = -1;

  if (pList)
    while (++idx < pList->currentElementCount){
      printf ("%dst data is %d\n",idx +1 , ((pList->pElement + idx)->));
    }
}
*/

// search data from position that i want to get
ArrayListNode* getALElement(ArrayList* pList, int position){
  if (pList != NULL || position < pList->currentElementCount)
    return (&pList->pElement[position]);
  else
    return NULL;
}

// get arraylist's length
int getArrayListLength(ArrayList* pList){
  int ret = 0;
  
  if (pList != NULL)
    ret = pList-> currentElementCount;
  return ret;
}

// clear arraylist's data
void clearArrayList(ArrayList* pList){
	if (pList){
		for(int i=0; i < pList->currentElementCount; i++){
			(pList->pElement + i)->arrivalTime = 0;
      (pList->pElement + i)->endTime = 0;
      (pList->pElement + i)->serviceTime = 0;
      (pList->pElement + i)->startTime = 0;
      (pList->pElement + i)->status = 0;
    }
    pList->currentElementCount = 0;
  }
}
