class Solution {
public:
    vector<int> solve(int n){
        if(n==1) return {1};
        int m=n/2;
        vector<int> lp=solve(m);
        vector<int> rp=solve(n-m);
        vector<int> res;
        for(int x:lp) res.push_back(2*x);
        for(int x:rp) res.push_back(2*x-1);
        return res;
    }
    vector<int> beautifulArray(int n) {
       return solve(n);
    }
};