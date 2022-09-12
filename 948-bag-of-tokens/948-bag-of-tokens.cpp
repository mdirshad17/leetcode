class Solution
{
    public:
        int bagOfTokensScore(vector<int> &tokens, int power)
        {
            int n = tokens.size();
            sort(tokens.begin(), tokens.end());
            int ans = 0;
            int i = 0, j = n - 1;
            int money = power;
            int cnt = 0;
            while (i <= j)
            {
                if (money >= tokens[i])
                {
                    money -= tokens[i];
                    i++;
                    cnt++;
                }
                else if (cnt)
                {
                    cnt--;
                    money += tokens[j];
                    j--;
                }
                else break;
                ans = max(ans, cnt);
            }
            return ans;
        }
};