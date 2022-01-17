class Solution {
public:
    int minOperations(vector<int>& t, vector<int>& arr) {
        map<int,int> mp;
        int n=t.size();
        for(int i=0;i<t.size();i++){
            mp[t[i]]=i;
        }
        vector<int> v;
        for(int i=0;i<arr.size();i++){
            if(!mp.count(arr[i]))continue;
                v.push_back(mp[arr[i]]);
        }
    
        // for(int i:v)cout<<i<<" ";
        // cout<<endl;
        vector<int> seq;
        seq.push_back(INT_MIN);
        for(int i=0;i<v.size();i++){
            if(v[i]<=seq.back()){
                auto it=lower_bound(seq.begin(),seq.end(),v[i])-seq.begin();
                seq[it]=v[i];
            }else{
                seq.push_back(v[i]);
            }
        }
        int len=seq.size();
        len--;
        return (n-len);
    }
};