class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int x:stones)pq.push(x);
        while(pq.size()>1){
            int d=pq.top();
            pq.pop();
            int e=pq.top();
            pq.pop();
            d-=e;
            if(d)pq.push(d);
        }
        if(pq.size())return pq.top();
        return 0;
    }
};