class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int g=0;
        for(int i:nums)g=__gcd(g,i);
        if(g==1)return 1;
        return 0;
    }
};