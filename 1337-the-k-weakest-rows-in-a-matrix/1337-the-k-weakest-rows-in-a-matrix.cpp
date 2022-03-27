class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int> > v;
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(int j=0;j<mat[i].size();j++){
                cnt+=mat[i][j];
                if(mat[i][j]==0)break;
            }
            v.push_back({cnt,i});
        }
        
        sort(v.begin(),v.end(),[](pair<int,int> & a,pair<int,int> & b){
             if(a.first==b.first)return a.second<b.second;
            return a.first<b.first;
        });
        vector<int> res;
        for(int i=0;i<k;i++){
            res.push_back(v[i].second);
        }
        return res;
    }
};