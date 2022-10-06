class TimeMap {
public:
    const static int N=2e5+10;
    set<int> st[N];
    unordered_map<string,int> STOI;
    map<pair<int,int>,string>RES;
    int s;
    TimeMap() {
        s=1;
    }
    
    void set(string key, string value, int timestamp) {
        int cnt;
        if(STOI.count(key)){
            cnt=STOI[key];
        }else {
            cnt=s;
            STOI[key]=s++;
        }
        RES[{cnt,timestamp}]=value;
        st[cnt].insert(timestamp);
    }
    
    string get(string key, int timestamp) {
         if(!STOI.count(key))return "";
         int cnt=STOI[key];
         auto it=st[cnt].upper_bound(timestamp);
         if(it==st[cnt].begin())return "";
         it--;
        int idx=(*it);
        return RES[{cnt,idx}];
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */