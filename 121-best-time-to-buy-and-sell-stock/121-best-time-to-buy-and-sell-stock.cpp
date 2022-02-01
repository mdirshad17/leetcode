class Solution {
public:
    int solve(int s,int n,vector<int> & v,int minel)
    {
        if(s>=n)
        {
            return 0;
        }
         minel=min(minel,v[s]);
        int op1=v[s]-minel;
        int op2=solve(s+1,n,v,minel);
        return max(op1,op2);
        
    }
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
         int f=solve(0,n,prices,INT_MAX);
        return f;
    }
};