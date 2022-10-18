class Solution {
public:
    string countAndSay(int n)
    {
        string x="1";
        
        for(int i=2;i<=n;i++)
        {string ans="";
            int l=x.size();
            char c= x[0];
            int counter=1;
            for(int j=1;j<l;j++)
            {
               if(c==x[j])
               {
                   counter++;
               }else
               {
                   ans+=to_string(counter)+c;
                   c=x[j];
                   counter=1;
               } 
            }if(counter>0)
            {ans+=to_string(counter)+c;
                
            }
            
            
        x=ans;
        }    
      return x;  
    }
};