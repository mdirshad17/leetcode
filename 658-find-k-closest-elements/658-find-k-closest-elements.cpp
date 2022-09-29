class Solution {
public:
    #define pii pair<int,int>
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       priority_queue<pii,vector<pii>,greater<pii>> pq;
       for(int i=0;i<arr.size();i++){
           pq.push({abs(x-arr[i]),arr[i]});
       } 
       vector<int> res;
       while(k--){
           res.push_back(pq.top().second);
           pq.pop();
       } 
        sort(res.begin(),res.end());
        return res;
    }
};