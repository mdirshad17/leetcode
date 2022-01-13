class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1)return 1;
        sort(points.begin(),points.end());
        int s=points[0][0];
        int e=points[0][1];
        int cnt=1;
        for(int i=1;i<n;i++){
            if(e>=points[i][0]){
                e=min(e,points[i][1]);
            }else {
                  cnt++;
                s=points[i][0];
                e=points[i][1];
            }
        }
        return cnt;
    }
};