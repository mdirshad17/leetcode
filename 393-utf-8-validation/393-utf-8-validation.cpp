class Solution
{
    public:
        bool validUtf8(vector<int> &data)
        {

            int n = data.size();
            for (int i = 0; i < n;)
            {
                int cnt = 0;
                for (int k = 7; k >= 0; k--)
                {
                    if ((data[i] &(1 << k)))
                    {
                        cnt++;
                    }
                    else break;
                }
                if(cnt==0){
                    i++;
                    continue;
                }
                if (cnt > 4||cnt==1) return 0;
                if((i+cnt)>n)return 0;
                for (int j = 1; j < cnt; j++) {
                    if((data[i+j]&(1<<7)) && ((data[i+j]&(1<<6))==0))continue;
                    
                    return 0;
                }
                // cout<<cnt<<endl;
                i+=cnt;
                
            }
            return 1;
        }
};