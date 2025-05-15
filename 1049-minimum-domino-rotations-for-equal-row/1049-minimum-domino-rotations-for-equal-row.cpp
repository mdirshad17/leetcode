class Solution {
public:
    int gen(vector<int>& tops, vector<int>& bottoms){
        int n=tops.size();
        int tc[7]={0};
        int bc[7]={0};
        for(int i=0;i<n;i++){
            tc[tops[i]]++;
            if(tops[i]!=bottoms[i]){
            bc[bottoms[i]]++;
            }
        }
        int ans=INT_MAX;
        for(int i=1;i<7;i++){
            int sum=tc[i]+bc[i];
            if(sum>=n){
                int nd=n-tc[i];
                int nb=n-bc[i];
                ans=min({ans,nd,nb});
            }
        }
        return ans==INT_MAX?-1:ans;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans1=gen(tops,bottoms);
        int ans2=gen(bottoms,tops);
        ans1=min(ans1,ans2);
        return ans1==INT_MAX?-1:ans1;

    }
};