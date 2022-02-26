class Solution {
public: 
    int integerBreak(int n) {
        if(n==3||n==2)return n-1;
        int num=0;
        if((n%3)==0)num=1;
        else if((n%3)==1)num=4,n-=4;
        else num=2,n-=2;
        for(int i=1;i<=n/3;i++)num=num*3;
        return num;
        
    }
};