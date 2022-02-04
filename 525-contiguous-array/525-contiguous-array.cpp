class Solution {
public:
    int findMaxLength(vector<int>& nums) 
    {
       int n=nums.size();
       for(int i=0;i<n;i++)
        {
          if(nums[i]==0)
          {
              nums[i]=-1;
          }
        }
        map<int,int> m;
        m[0]=-1;
        int pref=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            pref+=nums[i];
            if(m.find(pref)!=m.end())
            {
                 ans=max(ans,(i-m[pref]));
            }
            if(m.find(pref)==m.end())
            {
                m[pref]=i;
            }
            
        }
        return ans;
    }
};