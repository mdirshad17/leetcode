class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int sum=0;
        int n=piles.size();
        for(int i=1;i<(n-n/3);i+=2){
            sum+=piles[i];
        }
        return sum;
    }
};