class Solution {
public:
    #define vi vector<int>
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        // pair<int,pair<int,int> > 
        //vector<int>
        // a[0]-distance from origin
        // a[1]->x
        //a[2]->y
        auto compare=[](vector<int> & a,vector<int> & b){
              int dist1=(a[0]*a[0]+a[1]*a[1]);
              int dist2=(b[0]*b[0]+b[1]*b[1]);
            return dist1<dist2;
        };
        sort(points.begin(),points.end(),compare);
        while(points.size()>k){
            points.pop_back();
        }
        return points;
        
    }
};