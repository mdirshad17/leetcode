class Solution {
public:

    // Encodes a URL to a shortened URL.
    map<string,string> mp;
    // map<string,string> mpx;
    #define ll long long 

    #define M 999999900000001
    #define M1 1000000007
    int num=0;
    string encode(string s) {
        ll sum=0;
        ll sum1=0;
        
        for(int i=0;i<s.size();i++){
            sum=sum*97LL+(s[i]-' ');
            sum=sum%M;
            sum1=sum1*97LL+(s[i]-' ');
            sum1=sum%M1;
        }
        string g=to_string(sum)+'/'+to_string(sum1);
        mp[g]=s;
        return g;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));