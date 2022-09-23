class Solution
{
    public:
#define ll long long
#define M 1000000007
    int concatenatedBinary(int n)
    {

        ll mul = 1;
        ll ans = 0;
        while (n)
        {

            int br = n;
            while (br)
            {
                if ((br % 2))
                {
                    ans += mul;
                    ans=ans%M;
                }
                br = br / 2;

                mul = (mul *2LL) % M;
            }
            n--;
        }
        return ans;
    }
};