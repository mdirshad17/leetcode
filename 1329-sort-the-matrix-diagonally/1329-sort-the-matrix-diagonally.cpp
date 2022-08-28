class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        map<int,vector<int> > mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }
        for(auto & x:mp){
            sort(x.second.begin(),x.second.end());
        }
        for(auto x:mp){
            int num=x.first;
            int r=0,c=0;
            if(num<0){
                r=0;
                c=-num;
            }else{
                r=num;
                c=0;
            }
            for(int i=0;i<x.second.size();i++){
                mat[r][c]=x.second[i];
                r++;
                c++;
            }
            
        }
        return mat;
    }
};