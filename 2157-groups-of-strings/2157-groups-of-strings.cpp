class Solution {
public:
      const static int N = 2e4 + 5;
      vector<int> adj[N];
      int vis[N];
      vector<int> v;
      unordered_map<int, int> mp;
      int dfs(int s) {
            vis[s] = 1;
            // cout<<s<<" "<<cnts[s]<<endl;
            int ans = mp[v[s]];
            for (auto x : adj[s]) {

                  if (vis[x])continue;
                  // cout<<x<<" ";
                  ans += dfs(x);
            }
            return ans;
      }
      vector<int> groupStrings(vector<string>& w) {

           
            for (int i = 0; i < w.size(); i++) {
                  int num = 0;
                  for (int j = 0; j < w[i].size(); j++) {
                        num = num | (1 << (w[i][j] - 'a'));
                  }
                  v.push_back(num);
            }

            for (int i = 0; i < v.size(); i++) {
                  mp[v[i]]++;
            }
            v.clear();
            unordered_map<int, int> index;
            for (auto x : mp) {
                  v.push_back(x.first);
            }
          
            for (int i = 0; i < v.size(); i++) {
                  index[v[i]] = i;
            }
            // cout<<w.size()<<" "<<v.size()<<endl;
            for (int i = 0; i < v.size(); i++) {
                 // cout<<v[i]<<" ";
                  int num = v[i];
                  // insertion
                  for (int j = 0; j < 26; j++) {
                        int l = (num | (1 << j));
                        if (index.count(l)) {
                              adj[i].push_back(index[l]);
                              adj[index[l]].push_back(i);
                        }
                        // deletion
                        if ((num & (1 << j))) {
                              l = num ^ (1 << j);
                              if (index.count(l)) {
                                    adj[i].push_back(index[l]);
                                    adj[index[l]].push_back(i);
                              }
                        }
                  }
                  for (int j = 0; j < 26; j++) {
                        if ((num & (1 << j))) {
                              for (int k = 0; k < 26; k++) {
                                    if ((num & (1 << k)) == 0) {
                                          int l = num | (1 << k);
                                           l=l^(1<<j); 
                                          // cout<<l<<" ";
                                          if (index.count(l)) {
                                                adj[i].push_back(index[l]);
                                                adj[index[l]].push_back(i);
                                          }
                                    }
                              }
                        }
                  }

            }
          int cc=0;
          int mc=0;
           for(int i=0;i<v.size();i++){
               if(vis[i])continue;
               cc++;
               mc=max(mc,dfs(i));
           }
          return {cc,mc};


      }
};