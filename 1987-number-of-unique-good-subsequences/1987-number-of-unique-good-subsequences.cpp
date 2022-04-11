class Solution {
public:
    #define ll long long
    #define M 1000000007
    int numberOfUniqueGoodSubsequences(string s) {
        reverse(s.begin(),s.end());
        ll prev[2]={0};
        ll ansc=0;
        ll ansd=0;
        ll ans=1;
        int f=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            ll num=((2LL*ans-prev[s[i]-'0'])%M+M)%M;
            
            if(s[i]=='0'){
                ansc+=((ans-prev[s[i]-'0'])%M+M)%M;
                f=1;
            }
            prev[s[i]-'0']=ans;
            ans=num;
        }
        // cout<<ans<<" "<<ansc<<endl;
        
        return ((ans-ansc+(f-1))%M+M)%M;
        
        
    }
};