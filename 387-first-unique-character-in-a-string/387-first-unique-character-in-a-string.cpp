class Solution
{
    public:
        int firstUniqChar(string s)
        {
            int a[26] = { 0 };
            int n=s.size();
            for (int i = 0; i <n; i++)
            {
                a[s[i] - 'a']++;
            }
            for(int i=0;i<n;i++){
                if(a[s[i]-'a']==1){
                    return i;
                }
            }
            return -1;
        }
};