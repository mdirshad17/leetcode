class Solution
{
    public:
#define ll long long
    bool isPossible(vector<int> &v)
    {
        ll sum = 0;
        int n = v.size();
        // if(n==1)return (v[0]==0);
        priority_queue<ll> pq;
        for (int i = 0; i < n; i++)
        {
            sum += v[i];
            pq.push(v[i]);
        }
        while(pq.top()!=1){
            int tp=pq.top();
            pq.pop();
            sum-=tp;
        
            if(sum>=tp||sum==0||tp==0)return 0;
    
            ll mul=(tp+sum-1)/sum;
            // cout<<tp<<" "<<mul<<" "<<endl;
            tp-=(mul-1)*sum;
            sum+=tp;
            pq.push(tp);
        }
        return 1;
    }
};