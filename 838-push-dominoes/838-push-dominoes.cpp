class Solution {
public:
    string pushDominoes(string s) 
    {
        int n=s.size();
        vector<int> l(n,0);
        vector<int> r(n,0); 
        int el=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='R')
            {
                el=INT_MAX;
            }else if(s[i]=='L')
            {
                el=0;
            }else
            {
                el=max(0,el);
            }
            l[i]=el;
            el--;
        }
        el=0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='L')
            {
                el=INT_MAX;
            }else if(s[i]=='R')
            {
                el=0;
            }else
            {
                el=max(el,0);
            }
            
            r[i]=el;
            el--;
        }
        string res;
        for(int i=0;i<n;i++)
        {
            if(l[i]==r[i])
            {
                res.push_back('.');
            }else if(l[i]>r[i])
            {
                res.push_back('R');
            }else res.push_back('L');
        }
        return res;
          
    }
};