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
    ListNode * hh;
    bool check_pal(ListNode * head){
        if(!head)return true;
        bool checking=check_pal(head->next);
        if(head->val!=hh->val)return false;
        hh=hh->next;
        return checking;
    }
    bool isPalindrome(ListNode* head) {
        if(!head->next)return 1;
        hh=head;
        return check_pal(head);
    }
};