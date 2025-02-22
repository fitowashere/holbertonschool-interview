/**
 * check_cycle - Checks if a linked list has a cycle
 * @list: Pointer to the head of the linked list
 * Return: 1 if there is a cycle, 0 if there isn't
 */
int check_cycle(listint_t *list)
{
    listint_t *slow, *fast;

    /* If list is empty or has only one node, there can't be a cycle */
    if (list == NULL || list->next == NULL)
        return (0);

    slow = list;      /* Moves one step at a time */
    fast = list->next; /* Moves two steps at a time */

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        if (slow == fast)  /* If they meet, there is a cycle */
            return (1);
        
        slow = slow->next;         /* Move slow pointer one step */
        fast = fast->next->next;   /* Move fast pointer two steps */
    }

    return (0);  /* If we exit the loop, there is no cycle */
}
