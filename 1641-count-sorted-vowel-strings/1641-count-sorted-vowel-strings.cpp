class Solution {
public:
    int countVowelStrings(int n) {
        int a[5]={0};
        for(int i=0;i<5;i++){
            a[i]=1;
        }
        for(int i=1;i<n;i++){
            int sum=0;
           
            for(int j=4;j>=0;j--){
                sum+=a[j];
                a[j]=sum;
            }
           
            
        }
        
        int ans=0;
        for(int i=0;i<5;i++){
            ans+=a[i];
        }
        return ans;
    }
};