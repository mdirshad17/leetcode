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
    vector<int> adj[10005];
    int prs[10005];
    int vis[10005];
    void dfs(int s){
        vis[s]=1;
    
        for(auto x:adj[s]){
            
            if(prs[x]==0||vis[x])continue;
            
            dfs(x);
        }
    }
    int numComponents(ListNode* head, vector<int>& nums) {
        int pr=-1;
        while(head){
            int val=head->val;
            if(pr!=-1){
                adj[pr].push_back(val);
                adj[val].push_back(pr);
            }
            pr=head->val;
            head=head->next;
        }
        for(int x:nums){
            prs[x]=1;
        }
        int con_c=0;
        for(int x:nums){
            if(vis[x])continue;
            con_c++;
            dfs(x);
        }
        return con_c;
        
    }
};