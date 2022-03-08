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
    #define ll ListNode
    bool hasCycle(ListNode *head) {
        if(!head||!head->next)return 0;
        
        ll *s=head;
        ll *f=head;
        while(f && f->next){
            s=s->next;
            f=f->next->next;
            if(s==f)return 1;
        }
        return 0;
    }
};