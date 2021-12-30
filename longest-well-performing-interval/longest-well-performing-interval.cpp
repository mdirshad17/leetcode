class Solution {
public:
    int longestWPI(vector<int>& h) 
    {
        int n=h.size();
        int sum=0;
        int len=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            sum+=(h[i]>8?1:-1);
            if(sum>0){
                len=max(len,i+1);
            }else{
                int num=sum-1;
                if(mp.count(num)){
                    int lx=i-mp[num];
                    len=max(lx,len);
                }
            }
            // cout<<len<<" ";
            if(!mp.count(sum)){
                mp[sum]=i;
            }
        }
        return len;
        
    }
};