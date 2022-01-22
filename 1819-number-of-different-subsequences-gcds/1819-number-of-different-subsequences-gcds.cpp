class Solution {
public:
    
    const static int N=2e5+10;
    #define ll long long 
    ll a[N];
    
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        for(int i:nums) a[i]++;
        int ans=0;
        for(int i=1;i<N;i++){
            if(a[i]){
                ans++;
                continue;
            }
            int g=0;
            for(int j=2*i;j<N;j+=i){
                if(a[j]){
                    g=__gcd(g,j);
                    if(g==i)break;
                }
            }
            if(g==i)ans++;
        }
        
        
        return ans;
    }
};