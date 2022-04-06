class Solution {
public:
    
    #define M 1000000007
    #define ll long long 
    ll freq[105];
    ll get(int x,int y,int z){
        if(x==y && x==z){
            return (freq[x]*(freq[x]-1)*(freq[x]-2))/6;
        }
        if((x==y)){
            return (freq[x]*(freq[x]-1)*(freq[z]))/2;
        }
        if((x==z)){
            return (freq[x]*(freq[x]-1)*(freq[y]))/2;
        }
        if((z==y)){
            return (freq[x]*(freq[z]-1)*(freq[z]))/2;
        }
        return (freq[x]*freq[y]*freq[z]);
    }
    int threeSumMulti(vector<int>& arr, int target) {
        sort(begin(arr),end(arr));
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        int n=arr.size();
        ll ans=0;
        for(int i=0;i<n;i++){
            if(i!=0 && arr[i]==arr[i-1])continue;
            int j=i+1,k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum==target){
                    ans+=get(arr[i],arr[j],arr[k]);
                    ans=ans%M;
                    j++;
                    k--;
                    while((j)<n && arr[j]==arr[j-1]){
                        j++;
                    }
                    while((k>=0) && arr[k]==arr[k+1]){
                        k--;
                    }
                }else if(sum>target){
                    k--;
                    
                }else{
                    j++;
                }
            }
        }
        return ans;
    }
};