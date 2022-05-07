class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int lm[n];
        int minel=nums[0];
        for(int i=1;i<n;i++){
            lm[i]=minel;
            minel=min(minel,nums[i]);
        }
        stack<int> st;
        st.push(nums[n-1]);
        for(int i=n-2;i>=1;i--){
            if(lm[i]>=nums[i])continue;
            while(st.size() && st.top()<=lm[i]){
                st.pop();
            }
            if(st.size() && st.top()<nums[i])return 1;
            st.push(nums[i]);
        }
        return 0;
    }
};