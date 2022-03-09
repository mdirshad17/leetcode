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
    #define Node ListNode
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* nh=new Node(0);
        ListNode * p=nh;
        while(head){
            
            int f=0;
            while(head->next && head->next->val==head->val){
                head=head->next;
                f=1;
            }
            if(f==0){
            p->next=new Node(head->val);
            p=p->next;}
            head=head->next;
        }
        return nh->next;
    }
};