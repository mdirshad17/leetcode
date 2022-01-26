class Solution {
public:
    string maxValue(string s, int x) {
        int n=s.size();
        vector<char> v(n+1,'$');
       
        if(s[0]=='-'){
              v[0]='-';
            int f=0;
              for(int i=1;i<n;i++){
                  if((s[i]-'0')>x){
                      v[i]=(x+'0');
                      f=1;
                      break;
                  }
                  if(f)break;
              }
            if(f==0){
                v[n]=(x+'0');
            }
            int si=0;
            for(int i=1;i<n;){
               if(v[si]=='$'){
                  v[si++]=s[i];
                   i++;
               }else si++;
             }
        }else{
            int f=0;
              for(int i=1;i<=n;i++){
                  if((s[i-1]-'0')<x){
                      v[i-1]=(x+'0');
                      f=1;
                      break;
                  }
                  if(f)break;
              }
            if(f==0){
                v[n]=(x+'0');
            }
            int si=0;
            for(int i=0;i<n;){
               if(v[si]=='$'){
                  v[si++]=s[i];
                   i++;
               }else si++;
             }
        }
        
        string res;
        for(char c:v)res.push_back(c);
        return res;
    }
};