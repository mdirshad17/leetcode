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
    ListNode* partition(ListNode* head, int x) {
        if(!head||!head->next)return head;
        Node * Less=new Node(0);
        Node * LessTemp=Less;
        Node * Gre=new Node(0);
        Node * GreTemp=Gre;
        while(head){
            if(head->val>=x){
                GreTemp->next=head;
                GreTemp=GreTemp->next;
            }else {
                LessTemp->next=head;
                LessTemp=LessTemp->next;
            }
            head=head->next;
        }
        LessTemp->next=NULL;
        GreTemp->next=NULL;
        Less=Less->next;
        Gre=Gre->next;
        if(Less==NULL)return Gre;
        LessTemp->next=Gre;
        return Less;
    }
};