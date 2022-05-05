class MyStack {
public:
    queue<int> q1;    
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        queue<int> q;
        while(q1.size()>1){
            q.push(q1.front());
            q1.pop();
        }
        int d=q1.front();
        q1.pop();
        q1=q;
        return d;
    }
    
    int top() {
        queue<int> q;
        while(q1.size()>1){
            q.push(q1.front());
            q1.pop();
        }
        int d=q1.front();
        q.push(q1.front());
        q1.pop();
        q1=q;
        return d;  
    }
    
    bool empty() {
        // cout<<q1.size();
        return ((q1.size()==0));
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */