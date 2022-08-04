class Solution
{
    public:
        int mirrorReflection(int p, int q)
        {
            int l = (p *q) / __gcd(p, q);
            int a = l / p;
            int b = l / q;
            if ((a & 1) == 0 && (b & 1) == 1) return 0;
            if ((a & 1) == 1 && (b & 1) == 1) return 1;
            return 2;
        }
};