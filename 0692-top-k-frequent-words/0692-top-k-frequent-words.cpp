class compare{
   public: 
    
    bool operator()(pair<string,int> a, pair<string,int> b)
    {int i=0,j=0;
        if(a.second==b.second)
        {
         while(a.first[i]!='\0' || b.first[j]!='\0')
         { if(a.first[i]!=b.first[j])
         { return (a.first[i]>b.first[i]);}
         else 
         {
             i++;
             j++;
         }
            
        }}return a.second < b.second;
    }};
class Solution{
    public:
    vector<string> topKFrequent(vector<string>& words, int k)
    {vector<string> s;
        map<string,int> a;
        for(int i=0;i<words.size();i++)
        {
            a[words[i]]++;
        }
        priority_queue <pair<string,int>, vector<pair<string,int> >,compare> p(a.begin(),a.end());
       while(k--)
       {
          s.push_back(p.top().first);
           p.pop();
       }
     return s;
    }
};