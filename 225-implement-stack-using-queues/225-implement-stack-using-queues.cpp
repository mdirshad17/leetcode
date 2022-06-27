class MyStack
{
    public:
        queue<int> q1;
     queue<int> q2;
    MyStack() {
        
    }

    void push(int x)
    {
        q1.push(x);
        // cout<<q1.size()<<endl;
    }

    int pop()
    {
        // cout<<q1.size()<<endl;
        while (q1.size() > 1)
        {
            // cout<<q1.front()<<" ";
            q2.push(q1.front());
            q1.pop();
        }
        int d = q1.front();
        q1.pop();
        while(q2.size()){
            q1.push(q2.front());
            q2.pop();
        }
        
        return d;
    }

    int top()
    {
        
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int d = q1.front();
        q1.pop();
         while(q2.size()){
            q1.push(q2.front());
            q2.pop();
        }
        
        q1.push(d);
        
        return d;
    }

    bool empty()
    {
        // cout<<q1.size()<<endl;
        if(q1.size()==0)return 1;
        return 0;
        
    }
};

/**
 *Your MyStack object will be instantiated and called as such:
 *MyStack* obj = new MyStack();
 *obj->push(x);
 *int param_2 = obj->pop();
 *int param_3 = obj->top();
 *bool param_4 = obj->empty();
 */