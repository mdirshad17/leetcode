class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        vector<vector<double> > ct(100);
        ct[0].assign(1,poured);
        // ct[0][0]=poured;
        // int rem=poured;
        for(int i=1;i<100;i++){
            ct[i].assign(i+1,0);
            for(int j=0;j<ct[i-1].size();j++){
                
                double ex=max(ct[i-1][j]-1,0.00);
                ct[i-1][j]-=ex;
                ct[i][j]+=1.0*ex/2;
                ct[i][j+1]+=1.0*ex/2;
            } 
              
            }
      
        // for(int i=0;i<100;i++){
        //     for(int j=0;j<ct[i].size();j++){
        //         cout<<ct[i][j]<<" ";
        //     }cout<<endl;
        // }
         return ct[query_row][query_glass];
    }
};