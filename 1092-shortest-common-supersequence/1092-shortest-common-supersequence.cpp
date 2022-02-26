class Solution {
public:
    int dp[1005][1005];
    string res;
    // path tracking
    void getPath(int s1,int s2,int n,int m,string & s,string & p){
        if(s1>=n||s2>=m){
            res+=s.substr(s1);
            res+=p.substr(s2);
            return;
        }
        int op1=1+solve(s1+1,s2,n,m,s,p);
        int op2=1+solve(s1,s2+1,n,m,s,p);
        int op3=100000;
        if(s[s1]==p[s2])op3=1+solve(s1+1,s2+1,n,m,s,p);
        
        int f=min({op1,op2,op3});
        if(f==op1){
            res.push_back(s[s1]);
            getPath(s1+1,s2,n,m,s,p);
        }else if(f==op2){
            res.push_back(p[s2]);
             getPath(s1,s2+1,n,m,s,p);
        }else{
            res.push_back(s[s1]);
            getPath(s1+1,s2+1,n,m,s,p);
        }
    }
    
    // 
    int solve(int s1,int s2,int n,int m,string & s,string & p){
        if(s1>=n){
            return (m-s2);
        }
       
        if(s2>=m) return (n-s1);
         if(dp[s1][s2]!=-1)return dp[s1][s2];
        int op1=1+solve(s1+1,s2,n,m,s,p);
        int op2=1+solve(s1,s2+1,n,m,s,p);
        int op3=100000;
        if(s[s1]==p[s2])op3=1+solve(s1+1,s2+1,n,m,s,p);
        
        return dp[s1][s2]=min({op1,op2,op3});
    }
    string shortestCommonSupersequence(string str1, string str2) {
             memset(dp,-1,sizeof(dp));
             int n=str1.size();
             int m=str2.size(); 
             int f=solve(0,0,n,m,str1,str2);
             getPath(0,0,n,m,str1,str2);
             return res;
    }
};