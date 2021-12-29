class Solution {
public:
    vector<string> res;
    string ans;
    unordered_set<string> st;
    void solve(int s,int n,string & p,int sum,int cnt){
        if(sum<0)return;
       if(s>=n){
           // cout<<sum<<" "<<ans<<" "<<cnt<<endl;
          if(cnt==0 && sum==0 && !st.count(ans)) {
              res.push_back(ans);
              st.insert(ans);
          }
           
           return;
       }
        if(p[s]>='a' && p[s]<='z'){
            ans.push_back(p[s]);
            solve(s+1,n,p,sum,cnt);
            ans.pop_back();
            
        }else{
        
        ans.push_back(p[s]);
        int add=1*(p[s]=='('?1:-1);
        solve(s+1,n,p,sum+add,cnt);
        ans.pop_back();}
        
        solve(s+1,n,p,sum,cnt-1);
        
    }
    vector<string> removeInvalidParentheses(string s) {
        
        int cnt=0;
        int rmv=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]!=')'  &&  s[i]!='(')continue;
            if(s[i]==')'){
                if(cnt)cnt--;
                else rmv++;
            }else cnt++;
        }
        rmv+=cnt;
        // cout<<rmv<<" ";
        solve(0,n,s,0,rmv);
        return res;
    }
};