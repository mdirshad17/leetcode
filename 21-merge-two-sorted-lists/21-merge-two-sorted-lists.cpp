/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
           if(!l1 && !l2)
           {
               return NULL;
           }        
        if(!l1)
        {
            return l2;
        }
        if(!l2)
        {
            return l1;
        }
        ListNode * res=new ListNode(0);
        ListNode * x=res;
        while(l1 && l2)
        {
            if(l1->val<l2->val)
            {
                x->next=l1;
                x=x->next;
                l1=l1->next;
            }else 
            {
                x->next=l2;
                x=x->next;
                l2=l2->next;
            }
        }
        if(l1)
        {
            x->next=l1;
            x=x->next;
        }
        if(l2)
        {
            x->next=l2;
            x=x->next;
        }
        return  res->next;
    }
};