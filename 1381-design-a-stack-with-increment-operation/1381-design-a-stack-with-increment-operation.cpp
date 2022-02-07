class CustomStack {
public:
    vector<int> st;
    vector<int> sum;
    int sizes=0;
    CustomStack(int maxSize) {
        sizes=maxSize;
        st.clear();
        sum.clear();
    }
    
    void push(int x) {
        if(st.size()!=sizes){
            st.push_back(x);
            sum.push_back(0);
        }
    }
    
    int pop() {
        if(st.size()){
            int val;
            if(sum.size()){
                val= (sum.back()+st.back());
            }
            int sums=sum.back();
            sum.pop_back();
            st.pop_back();
            if(sum.size())sum.back()+=sums;
            return val;
            
        }
        return -1;
    }
    
    void increment(int k, int val) {
        k=min(k,(int)sum.size());
        --k;
        if(k>=0){
        sum[k]+=val;}
            
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */