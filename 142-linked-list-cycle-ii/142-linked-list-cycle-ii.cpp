/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)return NULL;
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                // cout<<"HELLO WORLD\n";
                if(slow==head)return head;
                
                slow=head;
                while(fast->next!=slow->next){
                    fast=fast->next;
                    slow=slow->next;
                }
                slow=slow->next;
                return slow;
            }
        }
        return NULL;
    }
};