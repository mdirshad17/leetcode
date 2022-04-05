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
    int get_len(ListNode * head){
        if(!head)return 0;
        return 1+get_len(head->next);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=get_len(head);
        if(len==n)return head->next;
        if(n==1){
            ListNode * g=head;
            while(g->next->next){
                g=g->next;
            }
            g->next=NULL;
            return head;
        }
      
        ListNode * f=head;
        while(n>=1){
            f=f->next;
            n--;
        }
        // cout<<f->val<<" ";
        ListNode * g=head;
        while(f->next){
            // cout<<f->val<<" "<<g->val<<endl;
            g=g->next;
            f=f->next;
        }
        cout<<g->val<<" ";
        g->next=g->next->next;
        return head;
    
    }
};