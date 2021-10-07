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
