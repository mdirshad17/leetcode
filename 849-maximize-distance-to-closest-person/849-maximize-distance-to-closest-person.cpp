class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
       vector<int> pos;
       int n=seats.size();
        // pos.push_back(-1);
        
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                pos.push_back(i);
            }
        }
    
        // pos.push_back(n);

        int ans=max(pos[0],n-1-pos.back());
        for(int i=1;i<pos.size();i++){
            int diff=(pos[i]-pos[i-1])/2;
           
            ans=max({ans,diff});
            
        }
        return ans;
    }
};