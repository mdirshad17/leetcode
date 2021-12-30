class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        int ns=tasks.size();
        int a[26]={0};
        for(int i=0;i<ns;i++){
            a[tasks[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(a[i]==0)continue;
            pq.push(a[i]);
        }
        int time=0;
        queue<pair<int,int> > q;
        while(pq.size()||q.size()){
             while(q.size() && (time-q.front().second)>n){
                 pq.push(q.front().first);
                 q.pop();
             }
              if(pq.size()){
              int d=pq.top();
              d--;
              pq.pop();
              if(d>0)q.push({d,time});
              }
            time++;
        }
        return time;
    }
};