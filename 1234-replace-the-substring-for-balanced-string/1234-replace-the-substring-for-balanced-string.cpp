class Solution
{
    public:
    #define ll long long
    
    unordered_map<char,int> mpx,mpg;
    int enough_extra(int extra){
        int l=min(mpg['Q'],mpx['Q']);
        int m=min(mpg['W'],mpx['W']);
        int n=min(mpg['E'],mpx['E']);
        int o=min(mpg['R'],mpx['R']);
        // cout<<l<<" "<<m<<" "<<n<<" "<<o<<" "<<extra<<endl;
        return ((l+m+n+o)>=extra);
    }
    int good(string & s,int m,int extra){
        int n=s.size();
        mpg['Q']=0;
        mpg['W']=0;
        mpg['E']=0;
        mpg['R']=0;
        for(int i=0;i<m;i++){
            mpg[s[i]]++;
        }
        if(enough_extra(extra))return 1;
        // cout<<"HELLO WORLD\n";
        for(int i=m;i<n;i++){
            mpg[s[i]]++;
            mpg[s[i-m]]--;
            if(enough_extra(extra))return 1;
        }
        return 0;
    }
    int balancedString(string s)
    {
        int n = s.size();
        int ans=n;
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        int extra=0;
        for(auto x:mp){
            if(x.second>n/4){
                mpx[x.first]=(x.second-n/4);
                extra+=(x.second-n/4);
            }
        }
        // cout<<extra<<endl;
        if(extra<=1)return extra;
        int l=1,r=n;
        // int ans=n;
        while(l<=r){
            int m=(l+r)/2;
            if(good(s,m,extra)){
                ans=m;
                r=m-1;
            }else l=m+1;
        }
        return ans;
    }
};