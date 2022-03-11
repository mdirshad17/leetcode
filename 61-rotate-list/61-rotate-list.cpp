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
    int get_length(ListNode * head){
        if(!head)return 0;
        return 1+get_length(head->next);
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next)return head;
        int n=get_length(head);
        k=k%n;
        ListNode * prev=NULL;
        ListNode * curr=head;
        ListNode * nn=head;
        ListNode * st=head;
        for(int i=1;i<=(n-k);i++){
            nn=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nn;
        }
        ListNode *  pr1=NULL;
        while(curr){
         nn=curr->next;
            curr->next=pr1;
            pr1=curr;
            curr=nn;   
        }
        st->next=pr1;
        curr=prev;
        prev=NULL;
        while(curr){
            nn=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nn;
        }
        return prev;
    }
};