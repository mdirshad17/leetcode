class Solution
{
    public:
#define ll long long
    int divide(int dx, int dy)
    {
        int mul = 1;
        ll dd=dx;
        ll di=dy;
        if (dd < 0)
        {
            mul ^= 1;
            dd = abs(dd);
        }
        if (di < 0)
        {
            mul ^= 1;
            di = abs(di);
        }
        
        ll num = 0;
        for (ll i = 31; i >= 0; i--)
        {
            ll numh = ((di*1LL) << i);
            if (numh <= dd)
            {
                dd -= numh;
                num = num | (1LL << i);
            }
        }
        if(mul==0){
            ll d=num;
            num-=d;
            num-=d;
        }
        // cout<<num<<" ";
        if(num>INT_MAX){
            num=INT_MAX;
        }else if(num<INT_MIN){
            num=INT_MIN;
        }
        return num;
    }
};