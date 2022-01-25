class Solution {
public:
    int getArea(vector<int> & v){
        int n=v.size();
        int l=*max_element(v.begin(),v.end());
        int ans=0;
        for(int i=1;i<=l;i++){
            unordered_map<int,int> mp;
            int sum=0;
            mp[sum]=-1;
            for(int j=0;j<n;j++){
                int l=0;
                if(v[j]>=i)l=i;
                sum+=(l-i);
                if(mp.count(sum)){
                    // cout<<"HELLO WORLD\n";
                    // cout<<mp[sum]<<" "<<j<<endl;
                    ans+=(j-mp[sum]);
                }else mp[sum]=j;
                
            }
        }
        return ans;
    }
    
    int numSubmat(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||mat[i][j]==0)continue;
                mat[i][j]+=mat[i-1][j];
            }
            int l=getArea(mat[i]);
            ans+=l;
           
        }
        return ans;
    }
};