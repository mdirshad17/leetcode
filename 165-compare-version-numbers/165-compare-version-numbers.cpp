class Solution {
public:
    vector<int> gen(string a){
        int n=a.size();
        vector<int> n1;
        int num=0;
         for(int i=0;i<n;i++){
            if(a[i]=='.'){n1.push_back(num);num=0;}
             else num=num*10+(a[i]-'0');
        }
        n1.push_back(num);
        return n1;
    }
    int compareVersion(string a, string b) {
        
        vector<int> n1=gen(a);
        vector<int> n2=gen(b);
        while(n1.size()<n2.size()){n1.push_back(0);}
        while(n2.size()<n1.size()){n2.push_back(0);}
        for(int i=0;i<n1.size();i++){
            if(n1[i]>n2[i])return 1;
            if(n1[i]<n2[i])return -1;
            
        }
        return 0;
        
    }
};