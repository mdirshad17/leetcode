class Solution {
public:
    int titleToNumber(string s) {
       int ans=0;
       long long  pr=1; 
       while(s.size()){
           ans+=(s.back()-'A'+1)*pr;
           pr=pr*26*1LL;
           s.pop_back();
       }
        return ans;
        
        
    }
};