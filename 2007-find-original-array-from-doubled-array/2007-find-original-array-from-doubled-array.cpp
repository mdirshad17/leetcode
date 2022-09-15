class Solution
{
    public:
        vector<int> findOriginalArray(vector<int> &changed)
        {
            map<int, int> mp;
            int n = changed.size();
            if(n&1)return {};
            for (int i = 0; i < n; i++)
            {
                mp[changed[i]]++;
                
            }
            sort(changed.begin(),changed.end(),[](int & a,int &b){
               if((a&1)==(b&1))return a<b; 
               return ((a&1)>(b&1)); 
            });
            vector<int> res;
            for(int x:changed){
               if(mp[x]==0)continue;
                mp[x]--;
               if(mp[2*x]==0)return {};
                res.push_back(x);
                mp[2*x]--;
            }
            return res;
        }
};