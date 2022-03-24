class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int ans=0;
        int n=people.size();
        int l=0,r=n-1;
        while(r>=l){
            if((people[r]+people[l])<=limit){
                r--;
                l++;
            }else r--;
            ans++;
        }
        return ans;
    }
};