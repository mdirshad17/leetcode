class NumArray
{
    public:
        const static int N = 3e4 + 10;
    int BIT[N];
    vector<int> v;
    void add(int x, int val)
    {
        while (x < N) BIT[x] += val, x += x &-x;
    }
    int sum(int x)
    {
       if(x==0)return 0;
        // cout<<x<<" "<<BIT[x]<<endl;
        return x ? BIT[x] + sum(x - (x &-x)) : 0;
    }
    NumArray(vector<int> &nums)
    {
        memset(BIT,0,sizeof(BIT));
        v.push_back(0);
        for (int i = 0; i < nums.size(); i++)
        {
           // cout<<BIT[i]<<" "; 
           v.push_back(nums[i]);
        }
        for(int i=1;i<v.size();i++){
            // cout<<v[i]<<" ";
              add(i,v[i]);
        }
    }

    void update(int index, int val)
    {
        index++;
        add(index,-1*v[index]);
        v[index]=val;
        add(index,v[index]);
    }

    int sumRange(int left, int right)
    {
        left++;
        right++;
        return sum(right)-sum(left-1);
    }
};

/**
 *Your NumArray object will be instantiated and called as such:
 *NumArray* obj = new NumArray(nums);
 *obj->update(index,val);
 *int param_2 = obj->sumRange(left,right);
 */