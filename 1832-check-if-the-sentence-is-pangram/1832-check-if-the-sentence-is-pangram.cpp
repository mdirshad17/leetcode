class Solution {
public:
    bool checkIfPangram(string S) {
        int a[26]={0};
        int n=S.size();
        for(int i=0;i<n;i++){
            a[S[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(a[i]==0)return 0;
        }
        return 1;
    }
};