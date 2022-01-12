class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& words) 
    {
         vector<int> v;
        vector<int> res;
        v.push_back(INT_MAX);
         for(int i=0;i<words.size();i++){
             string s=words[i];
             sort(s.begin(),s.end());
             int cnt=0;
             int is=0,j=0;
             int n=s.size();
             while(j<n && s[is]==s[j]){
                 j++;
             }
             v.push_back(j-is);
         }
        sort(v.begin(),v.end());
        // for(int i=0;i<n;i++)
        int nt=v.size()-1;
        for(int i=0;i<q.size();i++){
              string s=q[i];
            int n=s.size();
             sort(s.begin(),s.end());
             int cnt=0;
             int is=0,j=0;
             while(j<n && s[is]==s[j]){
                 j++;
                 cnt++;
             }
            // cout<<cnt<<" ";
             int idx=upper_bound(v.begin(),v.end(),cnt)-v.begin();
            // cout<<idx<<" ";
            int tot=nt-idx;
            res.push_back(tot);
             
            
        }
        return res;
        
    }
};