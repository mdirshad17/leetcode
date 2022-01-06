class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
          sort(trips.begin(),trips.end(),[](vector<int> & a,vector<int> & b){
              if(a[1]==b[1]){
                  return a[2]<b[2];
              }
               return a[1]<b[1]; 
          });
         int n=trips.size();
        
          priority_queue<pair<int,int> > q;
         
          int sum=0; 
          for(int i=0;i<n;i++){
              while(q.size() && abs(q.top().first)<=trips[i][1]){
                  sum-=q.top().second;
                  q.pop();
              }
              sum+=trips[i][0];
              q.push({-1*trips[i][2],trips[i][0]});
              if(sum>capacity) return 0;
          }
        return 1;
    }
};