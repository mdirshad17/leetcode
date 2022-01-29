class Solution {
public:
    int doit(vector<int> & nums)
    {
        int n=nums.size();
        stack<int> st;
        vector<int> l(n,-1);
        vector<int> r(n,n);
        for(int i=0;i<n;i++)
        {
            while(st.size() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(st.size()){
                l[i]=st.top();
            }
            st.push(i);
        }
        while(st.size()) st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            if(st.size()){
                r[i]=st.top();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int wd=(r[i]-l[i])-1;
            ans=max(wd*nums[i],ans);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& h) 
    {
        int n=h.size();
        int ans=doit(h);
        
        return ans;
    }
};