class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        map<string,int> mp;
        for(auto x:recipes){
            mp[x]=1;
        }
        for(auto x:ingredients){
          for(auto y:x){
            mp[y]=1;
          }
        }
        int node=0;
        for(auto &x:mp){
            x.second=node++;    
        }
        vector<int> adj[10005];
        vector<int> nums;
        int ind[10005];
        memset(ind,0,sizeof(ind));
        for(int i=0;i<recipes.size();i++){
            int node=mp[recipes[i]];
            nums.push_back(node);
            for(int j=0;j<ingredients[i].size();j++){
                int vnode=mp[ingredients[i][j]];
                adj[vnode].push_back(node);
                ind[node]++;
            }
        }
        queue<int> q;
        for(auto x:supplies){
            int i=mp[x];
            if(ind[i]==0){
                q.push(i);
            }
        }
        set<int> st;
        while(q.size()){
            int d=q.front();
            q.pop();
            // res.push_back()
            st.insert(d);
            for(int x:adj[d]){
                ind[x]--;
                if(ind[x]==0){
                    q.push(x);
                }

            }
        }
        vector<string> ans;
        for(auto x:recipes){
            int numb=mp[x];
            if(st.count(numb)){
                ans.push_back(x);
            }
        }
        return ans;

    }
};