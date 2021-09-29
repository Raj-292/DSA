/*
    Discussion Soln 1
*/

ListNode *removeNthFromEnd(ListNode *head, int n) 
{
    if (!head)
        return nullptr;

    ListNode new_head(-1);
    new_head.next = head;

    ListNode *slow = &new_head, *fast = &new_head;

    for (int i = 0; i < n; i++)
        fast = fast->next;

    while (fast->next) 
    {
        fast = fast->next;
        slow = slow->next;
    }

    ListNode *to_de_deleted = slow->next;
    slow->next = slow->next->next;
    
    delete to_be_deleted;

    return new_head.next;
}

/*
    Discussion Soln 2 : Without creating a new node
*/

ListNode* node = head, *offsetNode = head;
    for (int i = 0; i < n; ++i)
        node = node->next;
    
    // if node is NULL n is equal to the length of the linked list and we have to remove the head
    if (node == NULL)
        return head->next;
    
    while (node->next != NULL) {
        node = node->next;
        offsetNode = offsetNode->next;
    }
    
    offsetNode->next = offsetNode->next->next;
    
    return head;

