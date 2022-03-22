class Solution {
public:
    string getSmallestString(int n, int k) {
        string res;
        int sum=k;
        for(int i=1;i<n;i++){
            int rem=n-i;
            for(int j=1;j<=26;j++){
                int wl=(sum-j+(rem-1))/rem;
                if(wl<=26){
                    sum-=j;
                    res.push_back(('a'+(j-1)));
                    break;
                }
            }
        }
        cout<<sum<<endl;
        res.push_back(('a'+(sum-1)));
        return res;
    }
};