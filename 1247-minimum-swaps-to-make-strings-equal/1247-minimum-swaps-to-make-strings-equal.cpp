class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xc=0,yc=0;
        if(s1.size()!=s2.size())return 0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i])continue;
            if(s1[i]=='x')xc++;
            else yc++;
        }
        int tot=xc+yc;
        if(tot&1) return -1;
        int ans=xc/2+yc/2;
        xc=xc%2;
        yc=yc%2;
        ans+=2*yc;
        return ans;
        
    }
};