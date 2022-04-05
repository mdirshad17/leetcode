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
    ListNode* merge_it(ListNode * left,ListNode * right){
        ListNode * head=new ListNode(0);
        ListNode * p=head;
        while(left || right){
            if(left && right){
                if(left->val<=right->val){
                p->next=left;
                p=p->next;
                left=left->next;
                }else{
                p->next=right;
                p=p->next;
                right=right->next;}
            }else if(left){
                p->next=left;
                p=p->next;
                left=left->next;
            }else {
                p->next=right;
                p=p->next;
                right=right->next;
            }
        }
        p->next=NULL;
        return head->next;
        
    }
    // void print(ListNode * head){
    //     if(!head)return;
    //     cout<<head->val<<" ";
    //     print(head->next);
    // }
    ListNode * merge_sort(ListNode * head){
        
        if(!head||!head->next)return head;
        
           ListNode * left=head;
           ListNode * right=head;
           ListNode * p1=new ListNode(0);
           ListNode * g=p1;
        
           while(right && right->next){
               g->next=left;
               g=g->next;
               left=left->next;
               right=right->next->next;
               
           }
           g->next=NULL;
           // right=left;
           // left->next=NULL;
           // print(p1->next);
           // cout<<endl;
           // print(left);
           ListNode * lp=merge_sort(p1->next);
           ListNode * rp=merge_sort(left);
           return merge_it(lp,rp);
        // return head;
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        return merge_sort(head);
    }
};