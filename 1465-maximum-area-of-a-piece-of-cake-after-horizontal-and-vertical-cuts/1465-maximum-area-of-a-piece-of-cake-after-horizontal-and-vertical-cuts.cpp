class Solution {
public:
    int maxArea(int h, int w, vector<int>& hC, vector<int>& vC) {
        int hd=0;
        int wd=0;
        sort(hC.begin(),hC.end());
        sort(vC.begin(),vC.end());
        for(int i=0;i<hC.size();i++){
              int pr=0;
              int nn=h; 
              if(i-1>=0)pr=hC[i-1];
              if(i+1<hC.size())nn=hC[i+1];
              int diff=max(hC[i]-pr,nn-hC[i]);
              hd=max(hd,diff);
        }
        for(int i=0;i<vC.size();i++){
              int pr=0;
              int nn=w; 
              if(i-1>=0)pr=vC[i-1];
              if(i+1<vC.size())nn=vC[i+1];
              int diff=max(vC[i]-pr,nn-vC[i]);
              wd=max(wd,diff);
        }
        long long ans=(wd*1LL*hd*1LL)%(1000000007);
        return ans;
        
        
    }
};