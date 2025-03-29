class Solution {
public:
    const static int N=1e5+5;
    #define ll long long
    #define M  1000000007
    int COUNT[N];

    ll pows(int num,ll x){
        if(x==1) return num;
        ll res=1;
        ll n=num;
        while(x){
            if(x&1){
                res=res*1LL*n;
                res=res%M;
            }
            n=n*n;
            n%=M;
            x=x/2;
        }
        return res%M;
    }
    int  SOE[N];
    void soe(){
        memset(SOE,0,sizeof(SOE));
        SOE[1]=0;
        for(int i=2;i<N;i++){
            if(SOE[i]!=0)continue;
            for(int j=i;j<N;j+=i){
                    SOE[j]++;
            }
        }
        // COUNT[1]=0;
        // for(int i=2;i<N;i++){
        //       set<int> st;
        //       int num=i;
        //       while(num!=1){
        //          st.insert(SOE[num]);
        //          num=num/SOE[num];
        //       }
        //       COUNT[i]=st.size();  
        // }
    }
    int maximumScore(vector<int>& nums, int k) {
        soe();
        vector<int> nv;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nv.push_back(SOE[nums[i]]);
        }
        stack<int> st;
        int left[N];
        memset(left,-1,sizeof(left));
        for(int i=0;i<n;i++){
            while(st.size() && nv[i]>nv[st.top()]){
                st.pop();
            }
            if(st.size()){
                left[i]=st.top();
            }
            st.push(i);
        }
        while(st.size()){
            st.pop();
        }
        int right[N];
        memset(right,-1,sizeof(left));
        for(int i=n-1;i>=0;i--){
            while(st.size() && (nv[i]>=nv[st.top()])){
                st.pop();
            }
            if(st.size()){
                right[i]=st.top();
            }else right[i]=n;
            st.push(i);
        }
        // for(int i=0;i<n;i++){
        //     cout<<nums[i]<<" "<<nv[i]<<" \n";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<left[i]<<" "<<right[i]<<" \n";
        // }
        //  cout<<endl;
        ll ans=1;
        priority_queue<pair<int,ll> > pq;
        for(int i=0;i<n;i++){
            int lw=i-left[i];
            int rw=right[i]-i;
            ll occ= lw*1LL*rw;
            pq.push({nums[i],occ});
        }
        while(pq.size() && k){
            pair<int,ll> tp=pq.top();
            pq.pop();
            // cout<<tp.first<<" "<<tp.second<<" \n";
            ll count=tp.second;
            ll add=min(tp.second,k*1LL);
            // cout<<" ADD :: "<<add<<" \n";
            // cout<<ans<<" "<<pows(tp.first,add)<<" \n";
            ans*=1LL*pows(tp.first,add);
            k-=add;
            ans=ans%M;
        }
        return ans;
    
    }
};