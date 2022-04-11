class Solution {
public:
    #define ll long long 
    #define M 1000000007
    int distinctSubseqII(string s) {
        ll ans=1;
        ll prev[26]={0};
        int n=s.size();
        for(int i=0;i<n;i++){
           ll num=((2LL*ans-prev[s[i]-'a'])%M+M)%M;
           // cout<<num<<endl; 
            prev[s[i]-'a']=ans;
            ans=num;
            ans=ans%M;
        }
        return ((ans-1)%M+M)%M;
    }
};