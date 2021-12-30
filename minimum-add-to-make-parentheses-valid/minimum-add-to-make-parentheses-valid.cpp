class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int n=s.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                if(cnt)cnt--;
                else ans++;
            }else cnt++;
        }
        return ans+cnt;
    }
};