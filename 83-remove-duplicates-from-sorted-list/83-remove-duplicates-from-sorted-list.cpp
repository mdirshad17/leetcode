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
        if(head==nullptr||head->next==NULL)return head;
        
        Node * temp=head;
        Node * trav=head;
        while(trav!=nullptr){
            if(trav->val!=temp->val){
                temp->next=trav;
                temp=temp->next;
            }
            trav=trav->next;
        }
        if(temp->next!=NULL)temp->next=NULL;
        return head;
        
    }
};