class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        priority_queue<pair<int,int> > pq;
        map<int,int> mp;
        int n=nums.size();
        int max_num[n];
        memset(max_num,-1,sizeof(max_num));
        // int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            pq.push({mp[nums[i]],nums[i]});
            int num=pq.top().first;
            int number=pq.top().second;
            if(2*num>(i+1)){
                max_num[i]=number;
            }
        }
        mp.clear();
        mp[nums[n-1]]=1;
        for(int i=n-2;i>=0;i--){
            if(max_num[i]!=-1){
                 int num=mp[max_num[i]];
                 int sz=(n-i)-1;
                 if(2*num>sz) {
                    ans=i;
                 }  
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};