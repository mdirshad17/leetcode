class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int idx=-1;
        int sum=0;
        int n=gas.size();
        gas.insert(gas.end(),gas.begin(),gas.end());
        cost.insert(cost.end(),cost.begin(),cost.end());
        for(int i=0;i<2*n;i++)
        {
            int diff=(gas[i]-cost[i]);
            sum+=diff;
            if(sum<0)
            {
                sum=0;
                idx=-1;
            }else if(sum>=0 && idx==-1)
            {
                idx=i;
            }
            if(idx>=0)
            {
                int rem=(i-idx);
                if(rem==n-1)
                    return idx;
            }
        }
        return -1;
        // return idx;
    }
};