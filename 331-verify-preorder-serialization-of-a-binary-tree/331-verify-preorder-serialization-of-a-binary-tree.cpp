class Solution
{
    public:
        int pi = 0;
    int n;
    int solve(string & preorder,int f)
    {    
        pi+=f;
        if (pi >= preorder.size()) return true;
        if (preorder[pi] == '#')
        {
            pi++;
            return true;
        }
        while(pi<n && isdigit(preorder[pi])){
            pi++;
        }
        int l = (pi < n) ? solve(preorder,1) : 0;
        int m = (pi < n) ? solve(preorder,1) : 0;
        if (l && m) return 1;

        return 0;
    }
    bool isValidSerialization(string preorder)
    {    
        n = preorder.size();
        
        int l = solve(preorder,0);
        // cout<<pi<<" "<<n<<endl;
        if (l == 0) return 0;
        
        
        if (pi >= preorder.size()) return 1;
        return 0;
    }
};