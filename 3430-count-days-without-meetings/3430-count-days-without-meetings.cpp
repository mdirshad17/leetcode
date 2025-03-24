class Solution {
public:

    int countDays(int days, vector<vector<int>>& meetings) {
       sort(meetings.begin(),meetings.end(),[](vector<int> & a,vector<int> & b){
            if(a[0]==b[0]){
                return a[1]<b[1];
            }
            return a[0]<b[0];
       });
       int s=meetings[0][0];
       int e=meetings[0][1];
       int ans=s-1;
       int n=meetings.size();
       for(int i=1;i<n;i++){
           if(e>=meetings[i][0]){
             e=max(meetings[i][1],e);
           }else{
               ans+=(meetings[i][0]-e)-1;
               s=meetings[i][0];
               e=meetings[i][1];
           }
       }
       ans+=(days-e);
       return ans;

    }
};