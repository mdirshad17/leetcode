class Solution {
public:
    string reverseWords(string s) {
        
            string res;
            string formed="";
            int n=s.size();
            
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(formed.size()){
                    reverse(formed.begin(),formed.end());
                    res+=formed+" ";
                    formed="";
                }
                continue;
            }
            formed.push_back(s[i]);
        }
        if(formed.size()){
                    reverse(formed.begin(),formed.end());
                    res+=formed;
                    formed="";
                }
        while(res.size() && res.back()==' ')res.pop_back();
        return res;
        
    }
};