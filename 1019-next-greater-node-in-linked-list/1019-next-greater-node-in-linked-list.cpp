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
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head)return {};
        
        vector<int> res;
        stack<pair<int,int> > st;
        while(head){
            while(st.size() && head->val>st.top().first){
                res[st.top().second]=head->val;
                st.pop();
            }
            res.push_back(0);
            st.push({head->val,res.size()-1});
            head=head->next;
        }
        return res;
    }
};