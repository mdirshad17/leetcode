class MyCircularQueue {
public:
    int fi=-1,ri=-1;
    int a[3009];
    int sz;
    int ks=0;
    MyCircularQueue(int k) {
        sz=k;
        ks=k;
    }
    
    bool enQueue(int value) {
          if(sz>0){
              sz--;
              if(fi==-1){
                  a[++fi]=value;
                   ++ri;
              }else a[++ri]=value;
              return 1;
          }
        return 0;
    }
    
    bool deQueue() {
        if(fi!=-1 && fi<=ri){
            fi++;
            sz++;
            return 1;
        }
        return 0;
    }
    
    int Front() {
           if(fi!=-1 && fi<=ri)return a[fi];
        return -1;
    }
    
    int Rear() {
        if(fi<=ri && fi!=-1 && ri!=-1){
            return a[ri];
        }
        return -1;
    }
    
    bool isEmpty() {
        return (sz==ks);
    }
    
    bool isFull() {
    return (sz==0);
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