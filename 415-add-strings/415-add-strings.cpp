class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int n=num1.size();
        int m=num2.size();
        string ans;
        int i=n-1,j=m-1;
        int carry=0;
        while(i>=0 && j>=0){
            
            int d1=(num1[i]-'0');
            int d2=(num2[j]-'0');
            int sum=d1+d2+carry;
            int df=(sum%10);
            ans.push_back((df+'0'));
            carry=sum/10;
            i--;
            j--;
        }
        while(j>=0){
            int d2=num2[j]-'0';
            int sum=carry+d2;
            int df=(sum%10);
            ans.push_back((df+'0'));
            carry=sum/10;
            j--;
        }
        while(i>=0){
            int d2=num1[i]-'0';
            int sum=carry+d2;
            int df=(sum%10);
            ans.push_back((df+'0'));
            carry=sum/10;
            i--;
        }
        if(carry){
            ans.push_back(carry+'0');
        }
        while(ans.size()>1 && ans.back()=='0'){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};