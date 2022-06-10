class Solution {
public:
    
    int partition(vector<int> & v,int l,int r){
        int low=l;
        int pivot=v[r];
        for(int i=l;i<r;i++){
            if(v[i]<=pivot){
                swap(v[i],v[low]);
                low++;
            }
        }
        swap(v[low],v[r]);
        return low;
    }
    int get(vector<int> & v,int l,int r,int fi){
        int pi=partition(v,l,r);
        if(pi==fi)return v[pi];
        if(pi>fi)return  get(v,l,pi-1,fi);
        
        return get(v,pi+1,r,fi);
    }
    int findKthLargest(vector<int>& nums, int k) {
        
        random_shuffle(nums.begin(),nums.end());
        int n=nums.size();
        int fi=n-k;
        return get(nums,0,n-1,fi);
    }
};