class Solution {
public:
    // #Leetcode 1074
    int subarraysum(vector<int> & v,int k){
        int n=v.size();
        unordered_map<int,int> mp;
        mp[0]=1;
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            if(mp.count(sum-k)){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> b(m,0);
            for(int j=i;j<n;j++){
                for(int k=0;k<m;k++){
                    b[k]+=matrix[j][k];
                }
                int cnt=subarraysum(b,target);
                ans+=cnt;
            }
        }
        return ans;
    }
};