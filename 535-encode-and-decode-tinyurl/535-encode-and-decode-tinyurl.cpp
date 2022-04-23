class Solution {
public:

    // Encodes a URL to a shortened URL.
    map<string,string> mp;
    map<string,string> mpx;
    int num=0;
    string encode(string longUrl) {
        mp[longUrl]=to_string(num);
        mpx[mp[longUrl]]=longUrl;
        num++;
        return mp[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpx[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));