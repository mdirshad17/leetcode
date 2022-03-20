class Solution {
public:
    int minDominoRotations(vector<int>& t, vector<int>& b) {
        int n=t.size();
        int ans=INT_MAX;
        for(int i=1;i<=6;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(t[j]==i){
                    continue;
                }
                if(b[j]==i){
                    cnt++;
                }else{
                    
                    cnt=INT_MAX;
                    break;
                   
                }
            }
            ans=min(ans,cnt);
        }
        swap(b,t);
        for(int i=1;i<=6;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(t[j]==i){
                    continue;
                }
                if(b[j]==i){
                    cnt++;
                }else{
                    
                    cnt=INT_MAX;
                    break;
                   
                }
            }
            ans=min(ans,cnt);
        }
        if(ans>n)ans=-1;
        return ans;
    }
};