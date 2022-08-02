/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
#define Node ListNode
    Node *res = new Node(0);
    Node *temp = res;
    void solver(Node * l,int carry){
        if(l==NULL){
            if(carry){
                temp->next = new Node(carry);
            }
            return;
        }
        int sumh = (l->val + carry);
            int digithere = sumh % 10;
            carry = sumh / 10;
            temp->next = new Node(digithere);
            temp = temp->next;
           solver(l->next,carry);
    }
    void solve(Node *l1, Node *l2, int carry)
    {
        if (l1 == NULL) {
            
            solver(l2,carry);
            return;
        }
        if(l2==NULL){
            solver(l1,carry);
            return;
        }
        int sumh = (l1->val + l2->val + carry);
        int digithere = sumh % 10;
        carry = sumh / 10;
        temp->next = new Node(digithere);
        temp = temp->next;
        solve(l1->next, l2->next, carry);
    }
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        int carry = 0;
        // while (l1 && l2)
        // {
        //     int sumh = (l1->val + l2->val + carry);
        //     int digithere = sumh % 10;
        //     carry = sumh / 10;
        //     temp->next = new Node(digithere);
        //     temp = temp->next;
        //     l1 = l1->next;
        //     l2 = l2->next;
        // }
        // while (l1)
        // {
        //     int sumh = (l1->val + carry);
        //     int digithere = sumh % 10;
        //     carry = sumh / 10;
        //     temp->next = new Node(digithere);
        //     temp = temp->next;
        //     l1 = l1->next;
        // }
        // while (l2)
        // {
        //     int sumh = (l2->val + carry);
        //     int digithere = sumh % 10;
        //     carry = sumh / 10;
        //     temp->next = new Node(digithere);
        //     temp = temp->next;
        //     l2 = l2->next;
        // }
        // if (carry)
        // {
        //     temp->next = new Node(carry);
        // }
        solve(l1,l2,0);
        return res->next;
    }
};