class Solution {
public:
    #define pii pair<int,int>
    struct comp{
       bool operator()(pii & a,pii & b){
        
           double ai=1.0*(1.0*a.first-a.second)/(1.0*(a.first+1)*a.first);
          double bi=1.0*(1.0*b.first-b.second)/(1.0*(b.first+1)*b.first);
           // cout<<ai<<" "<<bi<<endl;
           return ai<bi;
       }  
    };
    double maxAverageRatio(vector<vector<int>>& c, int e) {
        
        priority_queue<pii,vector<pii>,comp> pq;
          int cnt=0;
        int n=c.size();
        for(int i=0;i<c.size();i++){
            if(c[i][1]==c[i][0]){
                cnt++;
                continue;
            }
            pq.push({c[i][1],c[i][0]});
        }
      
        for(int i=0;i<e;i++){
            if(!pq.size())break;
             
             pii tp=pq.top();
             pq.pop();
            // cout<<tp.first<<" "<<tp.second<<endl;
            tp.first+=1;
            tp.second+=1;
            pq.push(tp);
        }
        double res=0;
        while(pq.size()){
             pii tp=pq.top();
             pq.pop();
            res+=(1.0*tp.second)/tp.first;
        }
        res+=cnt;
        res=(res*1.0/n);
         
        return res;
        
    }
};