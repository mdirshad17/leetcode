class Solution {
public:
    bool good(int * a,int len,string s,int n)
    {
        int b[60]={0};
       for(int i=0;i<len;i++){
            b[s[i]-'A']++;
       }bool gotans=true;
        for(int i=0;i<60;i++)
        {
            if(a[i]>b[i])
            {
                gotans=false;
                break;
            }
        }
        if(gotans)
        {
            return true;
        }
        for(int i=len;i<n;i++)
        {
            b[s[i]-'A']++;
            b[s[i-len]-'A']--;
            gotans=true;
            for(int j=0;j<60;j++)
            {
            if(a[j]>b[j])
            {
                gotans=false;
                break;
             }
            }
            if(gotans)
            {
                return true;
            }
            
        }
        return false;
    }
    string minWindow(string s, string t) 
    {
       int n=s.size();
         int m=t.size();
        if(n<m)
        {
            return "";
        }int a[60]={0};
        for(int i=0;i<m;i++)
        {
            a[t[i]-'A']++;
        }
        int l=m,r=n;
        int len=n+1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(good(a,mid,s,n))
            {  len=min(len,mid);
                r=mid-1;
            }else
            {
                l=mid+1;
            }
        }
        if(len==n+1)
        {
            return "";
        }
        int b[60]={0};
        for(int i=0;i<len;i++)
        {
            b[s[i]-'A']++;
        }
        bool goodstr=true;
        for(int i=0;i<60;i++)
        {
            if(a[i]>b[i])
            {   goodstr=false;
                break;
            }
        }
        if(goodstr)
        {
            return (s.substr(0,len));
        }
        for(int i=len;i<n;i++)
        {
            b[s[i]-'A']++;
            b[s[i-len]-'A']--;
            goodstr=true;
            for(int j=0;j<60;j++)
            {
                if(a[j]>b[j])
                {  goodstr=false;
                    break;
                }
            }
            if(goodstr)
            {
                return s.substr(i-len+1,len);
            }
        }
        return "";
        
        
        
    }
};