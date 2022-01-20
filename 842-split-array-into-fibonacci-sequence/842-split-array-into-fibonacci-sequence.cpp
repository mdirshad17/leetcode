class Solution {
public:

    #define ll long long 
    ll MAX_NUM;
    int solve(int s,int n,string & p,vector<int> & v){
        if(s>=n){
            if(v.size()>2) {
                // cout<<"HELLO WORLD\n";
                return 1;
            }
            return 0;
        }
        ll num=0;
        if(p[s]=='0'){
            
            if(num<MAX_NUM){
                // fibonacci_check
                if(v.size()<2){
                    v.push_back(num);
                    if(solve(s+1,n,p,v)){
                        return true;
                    }
                    v.pop_back();
                }else{
                    int ns=v.size();
                    if(v[ns-1]+v[ns-2]==num){
                         v.push_back(num);
                    if(solve(s+1,n,p,v)){
                        return true;
                    }
                    v.pop_back();
                    }
                }
        }}else{
        for(int i=1;i<=10;i++){
            if(s+i<=n){
                // cout<<"HELLO WORLD\n";
            num=num*10LL+(p[s+i-1]-'0');
                // cout<<num<<" "<<MAX_NUM<<endl;
            if(num<MAX_NUM){
                // fibonacci_check
                // cout<<num<<endl;
                if(v.size()<2){
                    v.push_back(num);
                    if(solve(s+i,n,p,v)){
                        return true;
                    }
                    v.pop_back();
                }else{
                    int ns=v.size();
                    if(v[ns-1]*1LL+v[ns-2]*1LL==num){
                         v.push_back(num);
                    if(solve(s+i,n,p,v)){
                        return true;
                    }
                    v.pop_back();
                    }
                }
            }}
        }}
        return false;
    }
    vector<int> splitIntoFibonacci(string num) {
        MAX_NUM=(1LL<<31);
        // cout<<MAX_NUM<<endl;
        int n=num.size();
        vector<int> v;
        solve(0,n,num,v);
        return v;
        
    }
};