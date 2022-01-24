class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        int ns=n-k;
        stack<int> st;
        k=ns;
        for(int i=0;i<n;i++){
            while(st.size() && st.top()>nums[i] && k){
                k--;
                st.pop();
            }
            st.push(nums[i]);
        }
        while(st.size() && k){
            st.pop();
            k--;
        }
        vector<int> res;
        while(st.size()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
                    
    }
};