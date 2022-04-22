class MyHashMap {
public:
    list<pair<int,int>> a[1005];
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int rem=(key%1005);
        list<pair<int,int>> ::iterator it;
        for(it=a[rem].begin();it!=a[rem].end();it++){
            if((*it).first==key){
                (*it).second=value;
                return;
            }
        }
        a[rem].push_front({key,value});
    }
    
    int get(int key) {
         int rem=(key%1005);
        list<pair<int,int>> ::iterator it;
        for(it=a[rem].begin();it!=a[rem].end();it++){
            if((*it).first==key){
                return (*it).second;
            }
        }
       return -1;
    }
    
    void remove(int key) {
         int rem=(key%1005);
        list<pair<int,int>> ::iterator it;
        list<pair<int,int>> ::iterator itx;
        for(it=a[rem].begin();it!=a[rem].end();it++){
            if((*it).first==key){
               a[rem].erase(it);
                return;
            }
        }
        // a[rem].insert({key,value});
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */