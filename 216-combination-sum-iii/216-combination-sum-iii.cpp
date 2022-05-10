class Solution {
public:
    vector<vector<int> > res;
    vector<int> num;
    void solve(int s,int n,int k,int sum){
        if(sum<0||k<0)return;
        if(s>=n){
            if(sum==0 && k==0){
                res.push_back(num);
            }
            return;
        }
        num.push_back(s+1);
        solve(s+1,n,k-1,sum-(s+1));
        num.pop_back();
        solve(s+1,n,k,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        solve(0,9,k,n);
        return res;
    }
};