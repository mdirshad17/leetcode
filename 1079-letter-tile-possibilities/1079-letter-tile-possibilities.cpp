class Solution {
public:
    set<string> string_store;
    string formed;
    void string_builder(int n,int a[26]){
        if(n==0){
            string_store.insert(formed);
            return;
        }
        for(int i=0;i<26;i++){
           if(a[i]>0){
               char c='A'+i;
               formed.push_back(c);
               a[i]--;
               string_builder(n-1,a);
               a[i]++;
               formed.pop_back();
           } 
        }
    }
    int numTilePossibilities(string tiles) {
        
        int string_length=tiles.size();
        int frequency_count[26]={0};
        for(int i=0;i<string_length;i++){
            frequency_count[tiles[i]-'A']++;
        }
        for(int len=1;len<=string_length;len++){
             string_builder(len,frequency_count);
        }
        return string_store.size();
    }
};