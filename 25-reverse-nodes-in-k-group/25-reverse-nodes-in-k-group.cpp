/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
    #define Node ListNode
    int getLength(Node *head)
    {
        if (!head) return 0;
        return 1 + getLength(head->next);
    }
    void print(Node *head)
    {
        if (!head) return ;
        cout<<head->val<<" ";
        print(head->next);
    }
    Node* ReverseK(Node * head,int n,int k){
        if(n<k)return head;
        Node * curr=head;
        Node * prev=NULL;
        Node * next=NULL;
        Node * LNR=curr;
        for(int i=0;i<k;i++){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            
        }
        // print(prev);
        // cout<<endl;
        Node * Rest=ReverseK(curr,n-k,k);
        LNR->next=Rest;
        return prev;
        
    }
    ListNode* reverseKGroup(ListNode *head, int k)
    {
        int n = getLength(head);
        if (n < k) return head;
        return ReverseK(head,n,k);
    }
};