Find the first node of loop in linked list

/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution
{
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head)
    {
        if(!head)
            return -1;
        if(head == head->next)
            return head->data;
        Node* ans = head->next;
        head->next = head;
        return findFirstNode(ans);
    }
};