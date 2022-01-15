class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> mp;
        map<int,int> vis;
        int a[n+5];
        memset(a,1,sizeof(a));
        a[n-1]=0;
        for(int i=0;i<n;i++)
            mp[arr[i]].push_back(i);
        queue<pair<int,int> > q;
        int jr=0;
        q.push({n-1,arr[n-1]});
        while(q.size()){
            int ns=q.size();
            while(ns--){
                pair<int,int> d=q.front();
                q.pop();
                int num=d.second;
                int idx=d.first;
                
                if(!vis.count(num)){
                for(auto x:mp[num]){
                    if(a[x]>1+a[idx]){
                        a[x]=1+a[idx];
                        q.push({x,arr[x]});
                    }
                    vis[num]=1;
                }
                }
                if((idx-1)>=0 && (a[idx-1]>1+a[idx])) {q.push({idx-1,arr[idx-1]});a[idx-1]=1+a[idx];}
                if((idx+1)<n && (a[idx+1]>1+a[idx])) {q.push({idx+1,arr[idx+1]});a[idx+1]=1+a[idx];}
            }
            
        }
        return a[0];
    }
};