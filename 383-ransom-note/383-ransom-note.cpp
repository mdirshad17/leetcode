class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int a[26]={0};
        int n=ransomNote.size();
        int m=magazine.size();
        for(int i=0;i<n;i++){
            a[ransomNote[i]-'a']--;
        }
        for(int i=0;i<m;i++){
            a[magazine[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(a[i]<0)return 0;
        }
        return 1;
    }
};