class Solution {
public:
    int solve(int s,int e){
        if(s==e)return 0;
        if(s<e)return (e-s);
        if((s&1))return 1+solve(s+1,e);
        return 1+solve(s/2,e);
    }
    int brokenCalc(int startValue, int target) {
        return solve(target,startValue);
    }
};