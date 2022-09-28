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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        Node * curr=head;
        for(int i=0;i<n;i++){
            curr=curr->next;
        }
        Node * prev=head;
        Node * chan=head;
        while(curr){
            prev=chan;
            chan=chan->next;
            curr=curr->next;
        }
        if(chan==head)return head->next;
        prev->next=chan->next; 
        return head;
    }
};