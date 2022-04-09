class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        priority_queue<pair<int,int> > pq;
        for(auto x:mp){
            
            pq.push({-1*x.second,x.first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int> res;
        while(pq.size()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};