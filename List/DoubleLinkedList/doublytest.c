#include "doublylist.h"

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

 		removeDLElement(pList, 0);

  displayDoublyList(pList);
   clearDoublyList(pList);
   displayDoublyList(pList);

 	deleteDoublyList(pList);
 displayDoublyList(pList);
	}

	return 0;

}
