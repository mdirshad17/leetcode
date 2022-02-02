class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int a[26]={0};
        int b[26]={0};
        vector<int> res;
        if(s.size()==0||p.size()==0||s.size()<p.size())
        {
            return res;
        }
        for(int i=0;i<p.size();i++)
        {
            a[p[i]-'a']++;
            b[s[i]-'a']++;
        }
        bool flag=true;
         
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {flag=false;
                break;
            }
        }
         if(flag)
         {
             res.push_back(0);
         }
        
        for(int i=p.size();i<s.size();i++)
        {
              b[s[i]-'a']++;
              b[s[i-p.size()]-'a']--;
               flag=true;
            for(int i=0;i<26;i++)
             {
            if(a[i]!=b[i])
             {flag=false;
                break;
             }
            }
            if(flag)
            {
                res.push_back(i-p.size()+1);
            }
            
        }
        return res;
    }
};