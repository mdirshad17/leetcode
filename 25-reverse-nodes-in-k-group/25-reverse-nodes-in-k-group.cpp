/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
#define Node ListNode
    int getLength(Node *head)
    {
        if (!head) return 0;
        return 1 + getLength(head->next);
    }
    ListNode* reverseKGroup(ListNode *head, int k)
    {

        int n = getLength(head);
        if (n < k) return head;
        Node *heads = new Node(0);
        Node *temp = heads;
        Node *curr = head;
        while (curr != NULL && n >= k)
        {

           	//reverse this chunk
            Node *next = NULL;
            Node *LNR = curr;
            Node *prev = NULL;
            for (int i = 0; i < k; i++)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            temp->next = prev;
            temp = LNR;
            n -= k;
        }

        temp->next = curr;
        return heads->next;
    }
};