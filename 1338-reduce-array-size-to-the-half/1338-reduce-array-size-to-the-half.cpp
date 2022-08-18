class Solution
{
    public:

        const static int N = 1e5 + 2;
     int A[N];
    int minSetSize(vector<int> &arr)
    {
        memset(A, 0, sizeof(A));
        int n = arr.size();
        int dw = n/2;
        for (int x: arr)
        {
            A[x]++;
        }
        sort(A, A+N);
        int cnt=0;
        for(int i=N-1;i>0;i--){
            // cout<<A[i]<<" "; 
            n-=A[i];
            cnt++;
            // cout<<n<<endl;
            if(n<=dw)return cnt;
        }
        return -1;
    }
};