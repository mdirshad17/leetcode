class FreqStack {
public:
    unordered_map<int,int> mp;
    priority_queue<vector<int>> pq;
    int cnt_s;
    FreqStack() {
        cnt_s=0;
        mp.clear();
        while(pq.size()){
            pq.pop();
        }
    }
    
    void push(int val) {
        
       int cnt=mp[val];
       pq.push({cnt+1,++cnt_s,val}); 
       mp[val]++; 
    }
    
    int pop() {
        vector<int> tp=pq.top();
        pq.pop();
        int val=tp[2];
        mp[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */