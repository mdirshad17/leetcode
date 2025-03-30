class Solution {
public:
    vector<int> partitionLabels(string s) {
        int max_i[26];
        memset(max_i,0,sizeof(max_i));
        int n=s.size();
        for(int i=0;i<n;i++){
            max_i[s[i]-'a']=i;
        }
        int pi=0;
        vector<int> v;
        for(int i=0;i<n;i++){
            pi=max(pi,max_i[s[i]-'a']);
            if(pi==i){
                v.push_back(i+1);
            }
        }
        n=v.size();
        for(int i=n-1;i>0;i--){
            v[i]-=v[i-1];
        }

        return v;
    }
};