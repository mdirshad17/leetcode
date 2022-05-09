class Solution {
public:
    vector<string> res;
    string s;
    vector<string> v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void solve(int i,int n,string & p){
        if(i>=n){
            res.push_back(s);
            return;
        }
        int num=p[i]-'0';
        for(char c:v[num]){
            s.push_back(c);
            solve(i+1,n,p);
            s.pop_back();
        }
        
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n==0)return {};
        solve(0,n,digits);
        return res;
    }
};