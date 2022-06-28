class Solution {
public:
    string reorganizeString(string s) {
        int a[26]={0};
        int n=s.size();
        for(int i=0;i<n;i++){
            a[s[i]-'a']++;
        }
        priority_queue<pair<int,int> > pq;
        for(int i=0;i<26;i++){
            if(a[i]){
                pq.push({a[i],i});
            }
        }
        pair<int,int> used={0,0};
        string ans;
        while(pq.size()){
            pair<int,int> tp=pq.top();
            pq.pop();
            ans+=(tp.second+'a');
            tp.first--;
            if(used.first>0){
                pq.push(used);
            }
            used=tp;
        }
        int m=ans.size();
        if(m==n)return ans;
        return "";
    }
};