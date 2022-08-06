class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int nr=1+(minutesToTest/minutesToDie);
        if(buckets==1)return 0;
        int ans=0;
        int pr=1;
        while(pr<buckets){
            pr=pr*nr;
            ans++;
        }
        return ans;
    }
};