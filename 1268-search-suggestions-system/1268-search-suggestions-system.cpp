class Solution
{
    public:
        class Trie
        {
            public:
                Trie *child[26];
            vector<int> idx;
            Trie()
            {
                for (int i = 0; i < 26; i++)
                {
                    this->child[i] = NULL;
                }
                idx.clear();
            }
        };
    void insert(Trie *root, string &s, int num)
    {
        Trie *temp = root;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int val = s[i] - 'a';
            if (temp->child[val] == NULL)
            {
                temp->child[val] = new Trie();
            }
            temp = temp->child[val];
            if ((temp->idx.size()) < 3)
                temp->idx.push_back(num);
        }
    }
    vector<int> search(Trie *root, string &s)
    {
        Trie *temp = root;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int val = s[i] - 'a';
            if (temp->child[val] == NULL)
            {
                break;
            }
            temp = temp->child[val];
            if (i == n - 1) return temp->idx;
        }
        return {};
    }
    vector<vector < string>> suggestedProducts(vector<string> &pro, string sW)
    {
        Trie *root = new Trie();
        vector<vector < string>> ans;
        int n = pro.size();
        sort(pro.begin(), pro.end());
        for (int i = 0; i < n; i++)
        {
            insert(root, pro[i], i);
        }
        string g;

        for (int i = 0; i < sW.size(); i++)
        {
            g.push_back(sW[i]);
            vector<int> v = search(root, g);
            vector<string> t;
            for (int x: v) t.push_back(pro[x]);
            ans.push_back(t);
        }
        return ans;
    }
};