class Solution {
public:
    bool validMountainArray(vector<int>& v) {
        int n=v.size();
        if(n<3)return 0;
        int pr=v[0];
        int f=1;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(pr==v[i])return 0;
            if(f){
                if(pr>v[i])f=0;
                else cnt++;
              pr=v[i];
            }else {
                if(v[i]>=pr)return 0;
                else pr=v[i];
            }
        }
        return (f==0 && cnt);
        
    }
};