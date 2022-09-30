class Solution {
public:
	#define pii priority_queue  
	#define ff first
	#define ss second
    vector<vector<int>> getSkyline(vector<vector<int>>& B) {
          map<int,vector<int>>m;
    
        for(auto x:B)
        {
            int l=x[0];
            int r=x[1];
            int h=x[2];
                
                m[l].push_back(h);
                m[r].push_back(-h);
            
        }
    
    multiset<int>s;
    int curr_height=0;
    vector<vector<int>>ans;
    
        for(auto it=m.begin();it!=m.end();it++)
        {
            for(auto ele:it->second)
                if(ele>0)
                    s.insert(ele);
                else
                    s.erase(s.find(-ele));
            
            
            int height; 
                if(s.size()>0)
                    height = *s.rbegin();
                else 
                    height = 0;
            
                if(height!=curr_height)
                {
                    vector<int>temp;
                    temp.push_back(it->first);
                    temp.push_back(height);
                    ans.push_back(temp);
                }
            curr_height=height;
        }
    
    return ans;        
    }
};