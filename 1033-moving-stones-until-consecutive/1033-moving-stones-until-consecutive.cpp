class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
         vector<int> v={a,b,c};
         sort(v.begin(),v.end());
         int op1=0;
         if((v[0]+1==v[1])||(v[1]+1==v[2])||(v[0]+2==v[1])||(v[1]+2==v[2]))op1=1;
         else op1=2;
         if(v[0]+1==v[1] && 1+v[1]==v[2]) op1=0;
         int dist1=(v[1]-v[0])-1+(v[2]-v[1])-1;
         return {op1,dist1};
         
    }
};