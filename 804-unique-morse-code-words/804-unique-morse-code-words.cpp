class Solution
{
    public:
        string s[26] = { ".-",
            "-...",
            "-.-.",
            "-..",
            ".",
            "..-.",
            "--.",
            "....",
            "..",
            ".---",
            "-.-",
            ".-..",
            "--",
            "-.",
            "---",
            ".--.",
            "--.-",
            ".-.",
            "...",
            "-",
            "..-",
            "...-",
            ".--",
            "-..-",
            "-.--",
            "--.." };
    int uniqueMorseRepresentations(vector<string> &words)
    {
        unordered_set<string> st;
        for (auto x: words)
        {
            string res;
            for (char c: x)
            {
                res += s[c - 'a'];
            }
            st.insert(res);
        }
        return st.size();
    }
};