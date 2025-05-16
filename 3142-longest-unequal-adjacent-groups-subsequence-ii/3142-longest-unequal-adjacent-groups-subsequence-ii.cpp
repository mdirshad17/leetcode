class Solution {
public:
    int dp[1005][1005];
    int cool(string & a,string & b){
        int n=a.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=(a[i]!=b[i]);
            if(cnt>1) return 0;
        }
        return (cnt==1);
    }
    int solve(int i,int p,int n,vector<string>& words,vector<int>& groups){
        if(i>=n) return 0;
        if(dp[i][p+1]!=-1) return dp[i][p+1];
        int op1=solve(i+1,p,n,words,groups);
        int op2=0;
        if(p==-1){
            op2=1+solve(i+1,i,n,words,groups);
        }else{
            if(words[p].size()==words[i].size() && groups[i]!=groups[p] && cool(words[p],words[i])){
               op2=1+solve(i+1,i,n,words,groups);     
            }
        } 
        return dp[i][p+1]=max(op1,op2);
    } 
    vector<string> res;
    void getPath(int i,int p,int n,vector<string>& words,vector<int>& groups){
        if(i>=n) return;
        int op1=solve(i+1,p,n,words,groups);
        int op2=0;
        if(p==-1){
            op2=1+solve(i+1,i,n,words,groups);
        }else{
            if(words[p].size()==words[i].size() && groups[i]!=groups[p] && cool(words[p],words[i])){
               op2=1+solve(i+1,i,n,words,groups);     
            }
        } 
        if(op1>=op2){
            getPath(i+1,p,n,words,groups); 
        }else{
            res.push_back(words[i]);
            getPath(i+1,i,n,words,groups); 
        }
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        memset(dp,-1,sizeof(dp));
        int len=solve(0,-1,words.size(),words,groups);
        getPath(0,-1,words.size(),words,groups);
        cout<<len<<"\n";
        
        return res;
    }
};