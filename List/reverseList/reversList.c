void reverse(DoublyList **pList)
{
     DoublyListNode *tmp = NULL; 
     DoublyListNode *node = (*pList)->headerNode.pRLink;
   
     (*pList)->headerNode.pRLink->pLLink = NULL;

     while (node !=  NULL)
     {
       tmp = node->pLLink;
       node->pLLink = node->pRLink;
       node->pRLink = tmp;             
       node = node->pLLink;
     }
     
     if(tmp != NULL )
        (*pList)->headerNode.pRLink = tmp->pLLink;
}
