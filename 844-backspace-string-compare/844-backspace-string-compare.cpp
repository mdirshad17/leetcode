class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1,st2;
        for(char c:s){
            if(c=='#'){
                if(st1.size())st1.pop();
            }else st1.push(c);
        }
        for(char c:t){
            if(c=='#'){
                if(st2.size())st2.pop();
            }else st2.push(c);
        }
        if(st1.size()!=st2.size())return 0;
        while(st1.size()){
            if(st1.top()!=st2.top())return 0;
            st1.pop();
            st2.pop();
        }
        return 1;
    }
};