/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        #define Node ListNode
        ListNode* reverseBetween(ListNode *head, int left, int right)
        {
            Node *PR = NULL;
            Node *curr = head;
            for (int i = 2; i <= left; i++)
            {
                PR = curr;
                curr = curr->next;
            }
            Node *LNR = curr;
            Node *prev = NULL;
            Node *next = NULL;
            for (int i = left; i <= right; i++)
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            LNR->next = curr;
            if (PR == NULL) return prev;
            PR->next = prev;
            return head;
        }
};