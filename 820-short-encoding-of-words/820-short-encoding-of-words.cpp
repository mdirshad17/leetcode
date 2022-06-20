class Solution
{
    public:
        class Trie
        {
            public:
                Trie *child[26];
            Trie()
            {
                for (int i = 0; i < 26; i++)
                {
                    this->child[i] = NULL;
                }
            }
        };
    void insert(Trie *root, string &s)
    {
        int n = s.size();
        Trie *temp = root;
        for (int i = 0; i < n; i++)
        {
            int val = s[i] - 'a';
            if (temp->child[val] == NULL)
            {
                temp->child[val] = new Trie();
            }
            temp = temp->child[val];
        }
    }
    int search(Trie *root, string &s)
    {
        int n = s.size();
        Trie *temp = root;
        for (int i = 0; i < n; i++)
        {
            int val = s[i] - 'a';
            if (temp->child[val] == NULL)
            {
                return 0;
            }
            temp = temp->child[val];
        }
        return 1;
    }
    int minimumLengthEncoding(vector<string> &s)
    {
        sort(s.begin(), s.end(), [](string &a, string &b)
        {
            return a.size() > b.size();
	});
        Trie *root = new Trie();
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            reverse(s[i].begin(), s[i].end());
            int m = s[i].size();
            if (search(root, s[i])) continue;
            ans += (m + 1);
            insert(root, s[i]);
        }
        return ans;
    }
};