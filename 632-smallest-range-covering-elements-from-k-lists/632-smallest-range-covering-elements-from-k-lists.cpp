class Solution
{
    public:
        vector<int> smallestRange(vector<vector < int>> &nums)
        {
            vector<pair<int, int>> v;
            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = 0; j < nums[i].size(); j++)
                {
                    v.push_back({ nums[i][j],
                        i });
                }
            }
            int range=INT_MAX/100;
            vector<int> ans={0,0};
            sort(v.begin(), v.end());
            map<int,int> mp;
            int j=0;
            // for(int i=0;i<v.size();i++){
            //     cout<<v[i].first<<" "<<v[i].second<<endl;
            // }
            for(int i=0;i<v.size();i++){
                mp[v[i].second]++;
                while(mp.size()>=nums.size()){
                    int rangex=(v[i].first-v[j].first)+1;
                    if(rangex<range){
                        range=rangex;
                        ans[0]=v[j].first;
                        ans[1]=v[i].first;
                    }
                    mp[v[j].second]--;
                    if(mp[v[j].second]==0){
                        mp.erase(v[j].second);
                    }
                    j++;
                }
            }
            return ans;
        }
};