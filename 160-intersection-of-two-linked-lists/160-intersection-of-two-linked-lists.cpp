/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        int ll_size(ListNode *A)
        {
            int len = 0;
            while (A)
            {
                len++;
                A = A->next;
            }
            return len;
        }
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int n = ll_size(headA);
        int m = ll_size(headB);
        while (n > m)
        {
            headA = headA->next;
            --n;
        }
        while (m > n)
        {
            headB = headB->next;
            --m;
        }
        while (headA && headB)
        {
            if (headA== headB)
            {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};