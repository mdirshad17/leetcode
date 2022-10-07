class MyCalendarThree {
public:
    map<int,int> Arr;
    MyCalendarThree() {
        Arr.clear();
    }
    
    int book(int start, int end) {
        Arr[start]+=1;
        Arr[end]-=1;
        int prev=0;
        int ans=0;
        for(auto & x:Arr){
            prev=prev+x.second;
            // x.second=prev;
            ans=max(ans,prev);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */