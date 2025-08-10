Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *temp = new Node(-1);
    Node *ptr1 = list1;
    Node *ptr2 = list2;
    Node *ptr3 = temp;
    while (ptr1 && ptr2)
    {
        if (ptr1->data < ptr2->data)
        {
            ptr3->bottom = ptr1;
            ptr1 = ptr1->bottom;
        }
        else
        {
            ptr3->bottom = ptr2;
            ptr2 = ptr2->bottom;
        }
        ptr3 = ptr3->bottom;
    }
    if (!ptr1)
    {
        ptr3->bottom = ptr2;
    }
    if (!ptr2)
    {
        ptr3->bottom = ptr1;
    }
    return temp->bottom;
}
Node *flatten(Node *root)
{
    // Your code here
    if (root == NULL || root->next == NULL)
        return root;

    // Recursively flatten the next list
    root->next = flatten(root->next);

    // Merge current list with next list
    root = mergeTwoLists(root, root->next);

    return root;
}
