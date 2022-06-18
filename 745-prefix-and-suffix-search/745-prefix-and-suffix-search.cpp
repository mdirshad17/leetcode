class WordFilter
{
    public:
        class Trie
        {
            public:
                Trie *child[27];

            int a[27];
            Trie()
            {
                for (int i = 0; i < 27; i++)
                {
                    this->child[i] = NULL;
                    this->a[i] = -1;
                }
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
            temp->a[val] = max(temp->a[val], num);
        }
    }
    int search(Trie *root, string s)
    {
        int n = s.size();
        Trie *temp = root;

        for (int i = 0; i < n; i++)
        {
            int val = s[i] - 'a';
            if (!temp->child[val]) return -1;
            temp = temp->child[val];
            if (i == n - 1) return temp->a[val];
        }
        return -1;
    }
    Trie * root;
    void process(string & s,int num)
    {
        int n = s.size();
        string g;
        for (int i = n - 1; i >= 0; i--)
        {
            g.push_back(s[i]);
            reverse(g.begin(), g.end());
            string f=(g+'{'+s);
            insert(root,f,num);
            reverse(g.begin(), g.end());
        }
    }
    WordFilter(vector<string> &words)
    {
        root=new Trie();
        int n = words.size();
        unordered_map<string, int> mp;
        for (int i = n - 1; i >= 0; i--)
        {
            if (mp.count(words[i])) continue;
            process(words[i],i);
            mp[words[i]] = 1;
        }
    }

    int f(string prefix, string suffix)
    {
        string g = suffix + '{' + prefix;
        int l = search(root, g);
        return l;
    }
};

/**
 *Your WordFilter object will be instantiated and called as such:
 *WordFilter* obj = new WordFilter(words);
 *int param_1 = obj->f(prefix,suffix);
 */