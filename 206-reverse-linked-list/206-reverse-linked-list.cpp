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
    void print(Node *head)
    {
        while (head != NULL)
        {
            cout << head->val << " ";
            head = head->next;
        }
    }
   	// RP stands for reversedPart
    // LN stands for LastNode
    Node* reverseLL(Node *head)// O(N)
    {
        if (head == NULL || head->next == NULL) return head;
        Node *RP = reverseLL(head->next);
        Node *LN = head->next;
        LN->next = head;
        head->next = NULL;
        return RP;
    }
    ListNode* reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL) return head;
        Node *res = reverseLL(head);
        return res;
    }
};