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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * res=new ListNode(0);
        ListNode * p=res;
        while(head){
            
            if(head->val!=val){
                p->next=head;
                p=p->next;
            }
            head=head->next;
        }
        p->next=NULL;
        return res->next;
    }
};