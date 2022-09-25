class MyCircularQueue {
public:
    int CQ[5000];
    int li=0,ri=-1;
    int CQS;
    MyCircularQueue(int k) {
        CQS=k;
    }
    
    bool enQueue(int value) {
        int size=ri-li+1;
        if(size<CQS){
            ri++;
            CQ[ri]=value;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(li<=ri){
            li++;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(li<=ri)
        return CQ[li];
        
        return -1;
    }
    
    int Rear() {
       if(li<=ri) 
       return  CQ[ri];
        
        return -1;
    }
    
    bool isEmpty() {
        return (li>ri);
    }
    
    bool isFull() {
        return ((ri-li+1)==CQS);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */