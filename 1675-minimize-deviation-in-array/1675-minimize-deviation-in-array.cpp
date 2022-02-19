class Solution {
public:
    #define ll long long 
    int minimumDeviation(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int> > v;
        for(int i=0;i<n;i++){
            
            if((nums[i]%2)==0){
               ll num=nums[i];
               v.push_back({num,i}); 
               while((num%2)==0){
                   v.push_back({num/2,i});
                   // if(num%2)break;
                   num/=2;
               } 
            }else {
                v.push_back({nums[i],i});
                v.push_back({nums[i]*2,i});
            }
        }
        sort(v.begin(),v.end(),[](pair<int,int> & a,pair<int,int> & b){
           return a.first<b.first; 
        });
        // for(auto x:v){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        // cout<<n<<endl;
        map<int,int> mp;
        int j=0;
        int ans=INT_MAX;
        for(int i=0;i<v.size();i++){
            mp[v[i].second]++;
            while((int)mp.size()>=n){
                int diff=(v[i].first-v[j].first);
                ans=min(ans,diff);
                --mp[v[j].second];
                if(mp[v[j].second]==0){
                    mp.erase(v[j].second);
                }j++;
            }
        }
        return ans;
    }
};