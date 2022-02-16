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
    int getlen(ListNode * h){
        if(!h)return 0;
        return 1+getlen(h->next);
    }
    ListNode * solve(ListNode * head,int n){
        if(n<2)return head;
        
        ListNode * c=head;
        ListNode * p=NULL;
        ListNode * nn=NULL;
        ListNode * pr=head;
        int k=2;
        while(k--){
            nn=c->next;
            c->next=p;
            p=c;
            c=nn;
        }
        ListNode * x=solve(c,n-2);
        pr->next=x;
        return p;
        
    }
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)return head;
        int n=getlen(head);
        return solve(head,n);
    }
};