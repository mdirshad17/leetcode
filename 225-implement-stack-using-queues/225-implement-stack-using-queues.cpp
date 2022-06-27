class MyStack
{
    public:
        queue<int> q1;
     
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
        int n=q1.size();
        while (n>1)
        {
            q1.push(q1.front());
            q1.pop();
            n--;
        }
        int d = q1.front();
        q1.pop();
        // while(q2.size()){
        //     q1.push(q2.front());
        //     q2.pop();
        // }
        
        return d;
    }

    int top()
    {
        int n=q1.size();
        while (n > 1)
        {
            q1.push(q1.front());
            q1.pop();
            n--;
        }
        int d = q1.front();
        q1.pop();
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