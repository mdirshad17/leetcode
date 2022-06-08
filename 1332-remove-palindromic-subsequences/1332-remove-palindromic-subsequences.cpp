class Solution {
public:
    int removePalindromeSub(string s) {
        string g=s;
        reverse(g.begin(),g.end());
        if(g==s)return 1;
        return 2;
    }
};