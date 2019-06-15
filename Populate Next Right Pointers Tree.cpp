
TreeLinkNode* nextRight(TreeLinkNode* current)
{
    TreeLinkNode* currNext = current->next;
    
    while (currNext)
    {
        if (currNext->left)
            return currNext->left;
        else if (currNext->right)
            return currNext->right;
        currNext = currNext->next;
    }
    return NULL;
}
void Solution::connect(TreeLinkNode* A) {
    if (!A)
        return;
    A->next = NULL;
    while (A)
    {
        TreeLinkNode* temp = A;
        while (temp) //we traverse this temp pointer using next pointer so reccur till given level is not done 
        {
            if (temp->left) //if the node at current level has left child
            {
                if (temp->right) //then set it's left child's next pointer to the right available node which 
                                //would be current's right (if exist)
                    temp->left->next = temp->right; 
                else
                    temp->left->next = nextRight(temp); //if right child is not present then find which node is present in immediate right
            }
            if (temp->right) //if right is there set it's next pointer too
                temp->right->next = nextRight(temp);
                
            temp = temp->next; //this helps in traversing the given level as this level has already set it's next pointer 
        }
        if (A->left)//when level is done reccur for next level
            A = A->left;
        else if (A->right)
            A = A->right;
        else
            A = nextRight(A);
    }
