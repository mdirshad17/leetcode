class UndergroundSystem {
public:
    #define pss pair<string,string>
    #define pii pair<int,int>
    map<pss,pii> mp;
    map<int,string> mpx;
    map<int,int> mpt;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string s, int t) {
        mpx[id]=s;
        mpt[id]=t;
    }
    
    void checkOut(int id, string s, int t) {
        int st1=mpt[id];
        string st=mpx[id];
        mp[{st,s}].first+=(t-st1);
        mp[{st,s}].second+=1;
    }
    
    double getAverageTime(string s, string e) {
        double sum=mp[{s,e}].first;
        double n=mp[{s,e}].second;
        return (1.0*sum/n);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */