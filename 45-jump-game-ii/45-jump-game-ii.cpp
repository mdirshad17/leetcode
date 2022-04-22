class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jr=0;
        int mp=0;
        int max_reachable=0;
        for(int i=0;i<n;i++){
            if(mp<i){
                jr++;
                mp=max_reachable;
            }
            if(mp>=n-1)return jr;
            
            max_reachable=max(max_reachable,i+nums[i]);
           
        }
        return -1;
    }
};