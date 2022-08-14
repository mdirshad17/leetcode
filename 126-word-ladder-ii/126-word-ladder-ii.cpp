class Solution {
public:
  map<string, int> bfs(string s, string e, vector<string> & list)
  {
    set<string> st;
    set<string> visited;
    for (auto x : list)
    {
      st.insert(x);
    }
    map<string, int> mp;
    queue<string> q;
    q.push(s);
    visited.insert(s);
    int l = 0;
    while (!q.empty())
    {
      int n = q.size();
      while (n--)
      {
        string d = q.front();
        q.pop();
          // cout<<d<<" ";
        mp[d] = l;
        if (d == e)
        {
            // cout<<"Hello";
          return mp;
        }
        for (int i = 0; i < d.size(); i++)
        {
          for (int j = 0; j < 26; j++)
          {
            char f = d[i];
            char c = 'a' + j;
            d[i] = c;
              
            if (st.count(d) && !visited.count(d))
            {
              q.push(d);
              visited.insert(d);
            }
            d[i] = f;
          }
        }
      } l++;

    }
    map<string, int> ans;
    return ans;
  }
  vector<string> v;
  vector<vector<string>> res;
  map<string, int> mp;
  void getallPaths(string s, string e, int dist)
  {
    if (s == e )
    {
      v.push_back(e);
      reverse(v.begin(),v.end());
      res.push_back(v);
      reverse(v.begin(),v.end());
      v.pop_back();
      return;
    }
      // cout<<s<<" ";
    v.push_back(s);
    for (int i = 0; i < s.size(); i++)
    {
      for (int j = 0; j < 26; j++)
      {
        char f = s[i];
        char c = 'a' + j;
        s[i] = c;
        if (mp.count(s) && mp[s] == dist - 1)
        {
          getallPaths(s, e, dist - 1);
        }
        s[i] = f;
      }
    }v.pop_back();
  }
  vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
  {
    mp = bfs(beginWord, endWord, wordList);
    // cout << mp.size() << endl;
    if ((int)mp.size() == 0)
    {
      return {};
    }

    int dist = mp[endWord];
    getallPaths(endWord, beginWord, dist);
    return res;

  }
};