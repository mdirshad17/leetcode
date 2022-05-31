class Solution
{
    public:
        bool hasAllCodes(string s, int k)
        {
            int n=s.size();
            if(k>n)return 0;
            int len = (1 << k);
            int arr[len];
            memset(arr, 0, sizeof(arr));
            
            reverse(s.begin(),s.end());
            int mul=1;
            int num=0;
            for(int i=0;i<k;i++){
                 num=num+(mul*(s[i]-'0'));
                 mul=mul*2;
            }
            mul=mul/2;
            arr[num]=1;
            for(int i=k;i<n;i++){
                num=num/2;
                num=num+mul*(s[i]-'0');
                 arr[num]=1;
            }
            for (int i = 0; i < len; i++)
            {
                if (!arr[i]) return 0;
            }
            return 1;
        }
};