class Solution {
public:
    #define ll long long 
    bool reorderedPowerOf2(int n) {
        ll num=1;
        string g=to_string(n);
        sort(g.begin(),g.end());
        for(int i=1;i<=32;i++){
            string f=to_string(num);
            sort(f.begin(),f.end());
            if(f==g)return 1;
            num=num*2;
        }
        return 0;
    }
};